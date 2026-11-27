import random, statistics as st, sys
def run(days, winter=False, seed=0):
    rnd = random.Random(seed)
    weather, dur = "clear", 90
    water, flooded = 42, 0
    last_flood_end = None          # game-minute when flood receded
    minutes = days*1440
    flood_starts = []; windows = []      # per-day flags
    day_has_window = set(); in_window_prev=False; window_starts=[]
    for gm in range(1, minutes+1):
        # --- nature_d: one game minute
        if dur > 0: dur -= 1
        else:
            r = rnd.randrange(100); o = weather
            if o=="clear":
                weather = "clear" if r<50 else ("cloudy" if r<85 else "foggy"); dur = 90+rnd.randrange(90)
            elif o=="cloudy":
                if r<35: weather="clear"
                elif r<75: weather = "snowy" if winter else "rainy"
                else: weather="cloudy"
                dur = 80+rnd.randrange(60)
            elif o=="rainy":
                weather = "storm" if r<25 else ("cloudy" if r<60 else ("foggy" if r<80 else "rainy")); dur = 60+rnd.randrange(60)
            elif o=="storm":
                weather = "rainy" if r<70 else "cloudy"; dur = 45+rnd.randrange(45)
            elif o=="foggy":
                weather = "clear" if r<60 else "cloudy"; dur = 60+rnd.randrange(60)
            else:
                weather = "cloudy" if r<60 else "clear"; dur = 80+rnd.randrange(60)
        # --- world_state_d.world_tick every 5 game minutes
        if gm % 5 == 0:
            if weather=="storm": water += 6
            elif weather=="rainy": water += 2
            elif weather=="clear" and water>20: water -= 1
            water = max(15, min(100, water))
            if water >= 85:
                if not flooded:
                    flooded = 1; flood_starts.append(gm)
            elif water < 70 and flooded:
                flooded = 0; last_flood_end = gm
        # --- candidate 'novel-faithful' window: dawn(5-8h), clear sky, flood receded within last 24 game-hours
        hour = (gm//60) % 24
        w = (5 <= hour <= 8) and weather=="clear" and (not flooded) and last_flood_end is not None and (gm-last_flood_end) <= 24*60
        if w:
            day_has_window.add(gm//1440)
            if not in_window_prev: window_starts.append(gm)
        in_window_prev = w
    return len(flood_starts)/days, len(day_has_window)/days, window_starts, flood_starts
for label, winter in (("非冬季", False), ("冬季(雪取代雨)", True)):
    fl, wd = [], []; gaps=[]
    for s in range(40):
        f, w, ws, fs = run(1500, winter, s)
        fl.append(f); wd.append(w)
        # gap between distinct window days
        days = sorted({x//1440 for x in ws})
        gaps += [b-a for a,b in zip(days, days[1:])]
    print(f"[{label}]  40 次 × 1500 遊戲日")
    print(f"   山洪暴發頻率: 平均每遊戲日 {st.mean(fl):.3f} 次  → 約每 {1/st.mean(fl) if st.mean(fl)>0 else float('inf'):.1f} 遊戲日一次")
    print(f"   『水退石出＋晴朗破曉』窗口出現的遊戲日比例: {st.mean(wd)*100:.1f}%")
    if gaps:
        print(f"   相鄰窗口間隔(遊戲日): 中位 {st.median(gaps):.0f}, 平均 {st.mean(gaps):.1f}, P90 {sorted(gaps)[int(len(gaps)*.9)]}")
        print(f"   換算現實時間(1遊戲日=6小時): 平均約每 {st.mean(gaps)*6/24:.1f} 天出現一次窗口")
