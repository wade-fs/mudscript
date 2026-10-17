#!/usr/bin/env python3
"""
event_manager_model_check.py
============================
對 daemon/event_manager.c（第三版）的「手工移植模型」做窮舉檢查。

重要限制
--------
* 這不是在 MUD 驅動程式上執行的測試，而是把 LPC 的評估邏輯逐行移植成 Python。
  LPC 改了，這裡必須同步改，否則結論會過期。
* 整數除法與 LPC 一致（正整數下 // 等同 LPC 的 /）。
* 第 4、5 節的情境假設與參數（例如「JSON 缺事實鍵」）請依你實際資料調整。

對應關係
--------
  beast()            <-> evaluate_beast_surge()
  military_ending()  <-> evaluate_military_crisis()
  propagate_evidence <-> propagate_beast_to_military() 的第 3 段（物證傳播）

用法
----
  python3 event_manager_model_check.py
"""
import itertools
import collections

# ─────────────────────────────────────────────────────────────
# 1. 煞潮評估器（移植 evaluate_beast_surge）
# ─────────────────────────────────────────────────────────────
def beast(pressure, conf, div, cap, evid, trust):
    # effective_route_knowledge
    ek = min(3, conf + (2 if evid >= 3 else (1 if evid >= 1 else 0)))

    # 導流偏折百分比
    if div >= 2 and ek >= 2:
        pct = min(100, 65 + div * 5 + conf * 5 + evid * 5)
    elif div >= 1 or ek >= 1:
        pct = min(85, 25 + div * 15 + conf * 5 + evid * 5)
    else:
        pct = 10

    # 官道衝毀
    surge = pressure * pct // 50
    road = 2 if surge >= 4 else (1 if surge >= 2 else 0)

    # 殘餘動能衝擊：百分比正規化 (100 - pct) / 100，勘測度 conf 提供早期預警防護
    rp_raw = (pressure * (100 - pct) + 50) // 100
    rp = max(0, rp_raw - conf)
    surv = cap - rp
    if pct >= 70:
        state = "intact" if surv >= 2 else "starvation_risk"
    elif surv >= 1:
        state = "partial_damage"
    else:
        state = "devastated"

    panic = 1 if (trust <= 1 and rp > 0) else (1 if trust == 0 else 0)

    # derived_resilience (校準後確保正常遊玩保底 >= 1)
    if state == "intact" and not panic and trust >= 2:
        dres = 3
    elif state == "devastated" or surv <= 0 or (trust <= 0 and panic):
        dres = 0
    elif state == "starvation_risk" or (surv <= 1 and trust <= 0):
        dres = 1
    elif trust >= 1 and (state == "intact" or surv >= 2):
        dres = 2
    else:
        dres = 1
    return dict(road=road, dres=dres, state=state, pct=pct, panic=panic)


RANGES = dict(  # 與 beast_surge.json 的 min/max 對齊
    pressure=range(5), conf=range(4), div=range(4),
    cap=range(5), evid=range(4), trust=range(4),
)
NAMES = list(RANGES)
STATES = list(itertools.product(*[RANGES[n] for n in NAMES]))


def section1_causality():
    print(f"== 1. 煞潮 6 變數的因果影響（窮舉 {len(STATES)} 種狀態）==")
    print("   數字 = 在多少種『其餘變數組合』下，單獨改變該變數會改變該輸出")
    print(f"   {'變數':<10}{'官道破壞(road)':>16}{'黑石鋪韌性(derived_res)':>26}")
    for i, n in enumerate(NAMES):
        cr = cd = ctx = 0
        for combo in itertools.product(*[RANGES[m] for m in NAMES if m != n]):
            ctx += 1
            outs = []
            for v in RANGES[n]:
                a = list(combo)
                a.insert(i, v)
                outs.append(beast(*a))
            cr += len({o["road"] for o in outs}) > 1
            cd += len({o["dres"] for o in outs}) > 1
        print(f"   {n:<10}{cr:>10}/{ctx:<5}{cd:>16}/{ctx:<5}")

    for a, b in ((0, 1), (1, 2), (2, 3)):
        d = 0
        for s in STATES:
            dct = dict(zip(NAMES, s))
            if dct["evid"] != a:
                continue
            t = dict(dct)
            t["evid"] = b
            if beast(*[dct[n] for n in NAMES]) != beast(*[t[n] for n in NAMES]):
                d += 1
        print(f"   物證強度 {a}→{b} 造成輸出改變的狀態數: {d}")

    dd = collections.Counter(beast(*s)["dres"] for s in STATES)
    print("   derived_resilience 分佈:",
          {k: f"{v / len(STATES) * 100:.0f}%" for k, v in sorted(dd.items())})
    rd = collections.Counter(beast(*s)["road"] for s in STATES)
    print("   官道破壞度分佈:",
          {k: f"{v / len(STATES) * 100:.0f}%" for k, v in sorted(rd.items())})


# ─────────────────────────────────────────────────────────────
# 2. 韌性被傳播覆寫後，吃軍事階段陣前對峙的時間代價
# ─────────────────────────────────────────────────────────────
MIL_TIME_COSTS = 1   # military_crisis.json: confrontation -1 (ultimatum 已移除重複雙扣)


def resilience_at_resolution(dres):
    return max(0, dres - MIL_TIME_COSTS)


def section2_resilience():
    print("\n== 2. 韌性：傳播覆寫 + 陣前對峙時間代價 ==")
    ok = sum(1 for s in STATES if resilience_at_resolution(beast(*s)["dres"]) >= 1)
    print(f"   結算時 resilience >= 1 的煞潮狀態比例: {ok / len(STATES) * 100:.1f}%"
          "   (<1 一律進結局 D)")
    print("   derived_resilience → 結算時韌性:",
          {d: resilience_at_resolution(d) for d in range(4)})
    scenarios = {
        # (pressure, conf, div, cap, evid, trust)，cap/trust 已含 T-2/T-1 的 -1
        "完全不參與（預設，含 cap-1, trust-1）": (3, 0, 0, 3, 0, 1),
        "高分流+高勘測+高物證，但民心只有 1": (3, 3, 3, 3, 3, 1),
        "高分流+高勘測+高物證，且民心 >= 2": (3, 3, 3, 3, 3, 2),
        "中等防禦（div=1, conf=1, cap=3, trust=2）": (3, 1, 1, 3, 0, 2),
    }
    for k, v in scenarios.items():
        o = beast(*v)
        print(f"   {k:<38} → 官道破壞{o['road']} 韌性{o['dres']}"
              f" → 結算時 {resilience_at_resolution(o['dres'])}")


# ─────────────────────────────────────────────────────────────
# 3. 軍事結局（移植 evaluate_military_crisis）
# ─────────────────────────────────────────────────────────────
def military_ending(intel, verif, cost, res, witnesses, blood, tunnels, sources):
    if blood or res <= 0:
        return "D"
    if intel <= 1 and verif >= 2 and sources >= 2 and witnesses and res >= 1:
        return "A"
    if cost >= 2 and res >= 1:
        return "B"
    if intel >= 3 and tunnels and res >= 1:
        return "E"
    return "C"


def section3_endings():
    dims = (range(4), range(4), range(4), range(4), (0, 1), (0, 1), (0, 1), range(4))
    cnt = collections.Counter(military_ending(*s) for s in itertools.product(*dims))
    tot = sum(cnt.values())
    print(f"\n== 3. 軍事結局分佈（{tot} 組合；sources 假設 0~3 種）==")
    print("  ", {k: f"{cnt[k] / tot * 100:.1f}%" for k in "ABCDE"})

    mil_side = list(itertools.product(range(4), range(4), range(4), (0, 1), (0, 1), (0, 1), range(4)))
    mix = collections.Counter()
    n = 0
    for s in STATES:
        r = resilience_at_resolution(beast(*s)["dres"])
        for (i, v, c, w, b, t, sr) in mil_side:
            mix[military_ending(i, v, c, r, w, b, t, sr)] += 1
            n += 1
    print("   接上煞潮韌性後（兩邊均勻假設，只用來看結構，不代表真實機率）:")
    print("  ", {k: f"{mix[k] / n * 100:.1f}%" for k in "ABCDE"})


# ─────────────────────────────────────────────────────────────
# 4. 物證傳播的冪等性：JSON 缺少事實鍵時
# ─────────────────────────────────────────────────────────────
def propagate_evidence(ev_strength, json_has_fact_keys, times=2):
    """propagate_beast_to_military() 會在 T+1 與 T+2 各呼叫一次。
    set_fact 對未註冊的鍵會被拒絕，query_fact 對缺鍵回傳 0。"""
    last = 0
    verif, intel = 0, 3
    for _ in range(times):
        if ev_strength > last:
            diff = ev_strength - last
            prev = last
            if json_has_fact_keys:       # set_fact 成功 → 記住已傳播的強度
                last = ev_strength
            verif = min(3, verif + diff)
            if ev_strength >= 2 and prev < 2:
                intel = max(0, intel - 1)
    return verif, intel


def section4_idempotency():
    print("\n== 4. 物證傳播冪等性（T+1 與 T+2 各跑一次）==")
    print("   輸出 = (evidence_verifiability, intel_confidence)")
    for ev in (1, 2, 3):
        print(f"   物證強度 {ev}: JSON 有事實鍵 → {propagate_evidence(ev, True)}；"
              f"JSON 缺事實鍵 → {propagate_evidence(ev, False)}")


# ─────────────────────────────────────────────────────────────
# 5. duration 單位
# ─────────────────────────────────────────────────────────────
def section5_units():
    beast_d = [180, 240, 180, 60, 120]   # T-3..T+1（T+2 的 duration 為 0）
    mil_d = [300, 300, 300, 180]         # arrival..ultimatum
    GAME_MIN_REAL_SEC = 15               # nature_d：1 遊戲分鐘 = 15 現實秒
    print("\n== 5. JSON duration 的單位 ==")
    print(f"   煞潮 T-3→T+2 合計 {sum(beast_d)}；軍事 arrival→resolution 合計 {sum(mil_d)}")
    print(f"   若當『現實秒』（現行 call_out 的用法）：煞潮 {sum(beast_d) / 60:.0f} 分鐘、"
          f"軍事 {sum(mil_d) / 60:.0f} 分鐘")
    print(f"   若當『遊戲分鐘』：煞潮 {sum(beast_d) * GAME_MIN_REAL_SEC / 3600:.2f} 小時、"
          f"軍事 {sum(mil_d) * GAME_MIN_REAL_SEC / 3600:.2f} 小時")


if __name__ == "__main__":
    section1_causality()
    section2_resilience()
    section3_endings()
    section4_idempotency()
    section5_units()
