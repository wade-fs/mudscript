import random, statistics as st
def run(days, seed, drain_all, d, r_rain, r_storm, flood_at=85, recede_at=70, win_hours=24):
    rnd=random.Random(seed); weather,dur="clear",90; water,flooded=42,0; lf=None
    day_win=set(); floods=0
    for gm in range(1,days*1440+1):
        if dur>0: dur-=1
        else:
            r=rnd.randrange(100); o=weather
            if o=="clear": weather="clear" if r<50 else ("cloudy" if r<85 else "foggy"); dur=90+rnd.randrange(90)
            elif o=="cloudy":
                weather="clear" if r<35 else ("rainy" if r<75 else "cloudy"); dur=80+rnd.randrange(60)
            elif o=="rainy":
                weather="storm" if r<25 else ("cloudy" if r<60 else ("foggy" if r<80 else "rainy")); dur=60+rnd.randrange(60)
            elif o=="storm":
                weather="rainy" if r<70 else "cloudy"; dur=45+rnd.randrange(45)
            else:
                weather="clear" if r<60 else "cloudy"; dur=60+rnd.randrange(60)
        if gm%5==0:
            if weather=="storm": water+=r_storm
            elif weather=="rainy": water+=r_rain
            elif drain_all or weather=="clear":
                if water>20: water-=d
            water=max(15,min(100,water))
            if water>=flood_at:
                if not flooded: flooded=1; floods+=1
            elif water<recede_at and flooded: flooded=0; lf=gm
        h=(gm//60)%24
        if 5<=h<=8 and weather=="clear" and not flooded and lf is not None and gm-lf<=win_hours*60:
            day_win.add(gm//1440)
    return floods/days, len(day_win)/days
def avg(**kw):
    xs=[run(1200,s,**kw) for s in range(16)]
    return st.mean(x[0] for x in xs), st.mean(x[1] for x in xs)
print(f"{'模型':<44}{'山洪/遊戲日':>12}{'窗口日比例':>12}{'平均間隔(現實天)':>18}")
cases=[("現行 (僅晴天排水1, 雨+2, 暴雨+6)", dict(drain_all=False,d=1,r_rain=2,r_storm=6)),
       ("全天候排水1, 雨+2, 暴雨+6",          dict(drain_all=True,d=1,r_rain=2,r_storm=6)),
       ("全天候排水2, 雨+2, 暴雨+6",          dict(drain_all=True,d=2,r_rain=2,r_storm=6)),
       ("全天候排水3, 雨+2, 暴雨+6",          dict(drain_all=True,d=3,r_rain=2,r_storm=6)),
       ("全天候排水3, 雨+1, 暴雨+4",          dict(drain_all=True,d=3,r_rain=1,r_storm=4)),
       ("全天候排水4, 雨+1, 暴雨+4",          dict(drain_all=True,d=4,r_rain=1,r_storm=4)),
       ("全天候排水4, 雨+1, 暴雨+3",          dict(drain_all=True,d=4,r_rain=1,r_storm=3)),
       ("全天候排水5, 雨+1, 暴雨+3",          dict(drain_all=True,d=5,r_rain=1,r_storm=3))]
for name,kw in cases:
    f,w=avg(**kw)
    gap = (1/w*6/24) if w>0 else float('inf')
    print(f"{name:<40}{f:>12.4f}{w*100:>11.2f}%{gap:>16.1f}")

print("\n=== 結構性調整：提高洪水門檻 × 縮短『水退石出』有效時數 (其餘維持現行水位動態) ===")
print(f"{'洪水門檻':>8}{'有效時數':>8}{'山洪/遊戲日':>12}{'窗口日比例':>11}{'平均間隔(現實天)':>16}")
for fa in (85, 92, 97, 100):
    for wh in (24, 12, 6):
        xs=[run(1500,s,drain_all=False,d=1,r_rain=2,r_storm=6,flood_at=fa,recede_at=min(70,fa-10),win_hours=wh) for s in range(16)]
        f=st.mean(x[0] for x in xs); w=st.mean(x[1] for x in xs)
        gap=(1/w*6/24) if w>0 else float('inf')
        print(f"{fa:>8}{wh:>8}{f:>12.4f}{w*100:>10.2f}%{gap:>16.1f}")
