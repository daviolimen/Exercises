#!/usr/bin/env python3
"""Resumo do Codeforces para o log de treino.

Uso:
    python3 tools/cf_stats.py [handle] [--contests N] [--days D]

Mostra:
  1. rating atual, máximo e número de contests rated;
  2. os últimos N contests (ao vivo ou virtual) como linhas prontas para colar
     na tabela de log do plano: data, round, tipo, resolvidos com o minuto do AC,
     rank, delta de rating e tentativas erradas por problema;
  3. os problemas resolvidos em prática nos últimos D dias, por faixa de rating.

As colunas "causa" e "onde travou" ficam para você preencher: a categoria da
falha (conhecimento, observação, desisti cedo, implementação/bug, leitura) é
o que o script não tem como saber.

Só usa a biblioteca padrão. --offline DIR lê user.info.json, user.rating.json,
user.status.json e contest.list.json de DIR em vez de chamar a API.
"""
import argparse
import json
import sys
import time
import urllib.request
from collections import defaultdict
from datetime import datetime
from pathlib import Path
from zoneinfo import ZoneInfo

API = "https://codeforces.com/api/"
TZ = ZoneInfo("America/Sao_Paulo")
IGNORED_VERDICTS = {"OK", "COMPILATION_ERROR", "SKIPPED", "TESTING", None}


def fetch(method, params, offline):
    if offline:
        return json.loads((Path(offline) / f"{method}.json").read_text())["result"]
    query = "&".join(f"{k}={v}" for k, v in params.items())
    with urllib.request.urlopen(f"{API}{method}?{query}", timeout=30) as resp:
        data = json.load(resp)
    if data.get("status") != "OK":
        sys.exit(f"Erro da API em {method}: {data.get('comment')}")
    time.sleep(0.5)  # a API limita a cerca de 1 chamada a cada 2 segundos por IP
    return data["result"]


def date(ts):
    return datetime.fromtimestamp(ts, TZ).strftime("%d/%m/%y")


def contest_rows(status, rating_by_contest, contest_names, limit):
    """Agrupa submissões de contest (ao vivo ou virtual) por participação."""
    groups = defaultdict(list)
    for s in status:
        kind = s["author"]["participantType"]
        if kind in ("CONTESTANT", "OUT_OF_COMPETITION", "VIRTUAL") and "contestId" in s:
            groups[(s["contestId"], kind == "VIRTUAL")].append(s)

    rows = []
    for (cid, virtual), subs in groups.items():
        subs.sort(key=lambda s: s["creationTimeSeconds"])
        start = subs[0]["author"].get("startTimeSeconds", subs[0]["creationTimeSeconds"])
        solved, wrong, tried = {}, defaultdict(int), set()
        for s in subs:
            idx = s["problem"]["index"]
            tried.add(idx)
            if idx in solved:
                continue
            if s["verdict"] == "OK":
                solved[idx] = s["relativeTimeSeconds"] // 60
            elif s["verdict"] not in IGNORED_VERDICTS:
                wrong[idx] += 1
        rated = rating_by_contest.get(cid) if not virtual else None
        rows.append({
            "start": start,
            "date": date(start),
            "name": contest_names.get(cid, f"Contest {cid}"),
            "kind": "Virtual" if virtual else "Ao vivo",
            "solved": ", ".join(f"{i} ({m} min)" for i, m in sorted(solved.items())) or "—",
            "rank": str(rated["rank"]) if rated else "—",
            "delta": f"{rated['newRating'] - rated['oldRating']:+d}" if rated else "—",
            "wrong": ", ".join(f"{i}: {n}" for i, n in sorted(wrong.items())) or "nenhuma",
            "stuck": ", ".join(sorted(tried - solved.keys())) or "",
        })
    rows.sort(key=lambda r: r["start"], reverse=True)
    return rows[:limit]


def practice_summary(status, days):
    since = time.time() - days * 86400
    solved = {}
    for s in status:
        if (s["author"]["participantType"] == "PRACTICE" and s["verdict"] == "OK"
                and s["creationTimeSeconds"] >= since):
            p = s["problem"]
            solved[(p.get("contestId"), p["index"])] = p.get("rating")
    bands = defaultdict(int)
    for r in solved.values():
        bands["sem rating" if r is None else f"{r // 100 * 100}"] += 1
    return len(solved), dict(sorted(bands.items()))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("handle", nargs="?", default="daviolimen")
    ap.add_argument("--contests", type=int, default=5, help="quantos contests listar (padrão 5)")
    ap.add_argument("--days", type=int, default=7, help="janela da prática em dias (padrão 7)")
    ap.add_argument("--offline", metavar="DIR", help="ler JSONs salvos em vez de chamar a API")
    args = ap.parse_args()

    info = fetch("user.info", {"handles": args.handle}, args.offline)[0]
    rating = fetch("user.rating", {"handle": args.handle}, args.offline)
    status = fetch("user.status", {"handle": args.handle, "from": 1, "count": 10000}, args.offline)
    contests = fetch("contest.list", {"gym": "false"}, args.offline)

    rating_by_contest = {r["contestId"]: r for r in rating}
    names = {c["id"]: c["name"] for c in contests}

    print(f"## {info['handle']}: {info.get('rating', '—')} (máx. {info.get('maxRating', '—')}), "
          f"{len(rating)} contests rated\n")

    print(f"### Últimos {args.contests} contests\n")
    print("| Data | Round | Tipo | Resolvidos | Rank | Δ rating | Tentativas erradas | Tentou e não resolveu |")
    print("| --- | --- | --- | --- | --- | --- | --- | --- |")
    for r in contest_rows(status, rating_by_contest, names, args.contests):
        print(f"| {r['date']} | {r['name']} | {r['kind']} | {r['solved']} | {r['rank']} | "
              f"{r['delta']} | {r['wrong']} | {r['stuck']} |")

    total, bands = practice_summary(status, args.days)
    print(f"\n### Prática nos últimos {args.days} dias: {total} problemas resolvidos\n")
    for band, n in bands.items():
        print(f"- {band}: {n}")


if __name__ == "__main__":
    main()
