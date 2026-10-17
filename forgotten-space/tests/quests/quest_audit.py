import json, glob, os, re, sys, collections
R = sys.argv[1]
def rd(p):
    return open(os.path.join(R,p), encoding='utf-8', errors='replace').read()

# --- load quests
Q = {}
for f in sorted(glob.glob(R+'/quests/*/*.json')):
    d = json.load(open(f, encoding='utf-8')); Q[d['id']] = (f, d)

# --- what the engine can actually receive
engine_src = rd('daemon/quest_engine_d.c')
emitters = collections.defaultdict(set)   # event -> set(sources)
for f in glob.glob(R+'/**/*.c', recursive=True):
    if f.endswith('quest_engine_d.c'): continue
    s = open(f, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'trigger_event\(\s*\w+\s*,\s*"(\w+)"\s*,\s*\(\[(.*?)\]\)\)', s, re.S):
        ev, body = m.group(1), m.group(2)
        rel = os.path.relpath(f, R)
        if ev == 'action':
            v = re.search(r'"verb"\s*:\s*"([^"]+)"', body); t = re.search(r'"target"\s*:\s*"([^"]+)"', body)
            emitters['action'].add((rel, v.group(1) if v else '?', t.group(1) if t else None))
        else:
            emitters[ev].add((rel,))
# also dynamic verbs (variable verb) - report separately
dyn = []
for f in glob.glob(R+'/d/village/*.c'):
    s = open(f, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'trigger_event\(([^;]*?)\);', s, re.S):
        if '"verb"' in m.group(1) and not re.search(r'"verb"\s*:\s*"', m.group(1)):
            dyn.append(os.path.basename(f))
action_verbs = {(v,t) for (_,v,t) in emitters['action']}

# --- rooms / npcs / items
rooms = [os.path.splitext(os.path.basename(p))[0] for p in glob.glob(R+'/d/village/*.c')]
npc_ids = {}
for f in glob.glob(R+'/clone/npc/*.c'):
    s = open(f, encoding='utf-8', errors='replace').read()
    # NPC 的 id 可能寫在 set_name(...) 的陣列，也可能寫在 set_id(...)（先前只看 set_name 造成 lu / zhao si 誤報）
    id_blobs = re.findall(r'set_name\([^;]*?\(\{(.*?)\}\)', s, re.S) + re.findall(r'set_id\(\s*\(\{(.*?)\}\)', s, re.S) + re.findall(r'add_id\(\s*\(\{(.*?)\}\)', s, re.S)
    ids = set(re.findall(r'"([A-Za-z][A-Za-z _]*)"', ' '.join(id_blobs)))
    ids |= {os.path.splitext(os.path.basename(f))[0]}
    npc_ids[os.path.basename(f)] = {i.lower() for i in ids}
all_npc_ids = set().union(*npc_ids.values())
alias_ok = {'huoluo_dan','san','herb_dew','dew_herb','tainted_pelt','pelt','ore_chunk','ore','tianmen','ancient_token','tianmen_token','mine_blueprint','blueprint','steel_chisel','chisel','disha_wine','wine','mountain_talisman','talisman'}

def steps_of(q):
    if q.get('stages'):
        for st in q['stages']:
            for s in st.get('steps', []): yield st['stage'], s
    else:
        for s in q.get('steps', []): yield 1, s

print("="*70); print("A. 步驟覆蓋矩陣：該步驟的事件，引擎實際收得到嗎？"); print("="*70)
for qid,(f,q) in Q.items():
    print(f"\n[{q['category']}/{qid}]  type={q.get('type')}")
    for stg, s in steps_of(q):
        tt = s.get('target_type'); flag=''; why=''
        if tt=='talk':
            flag = 'OK' ; why='cmd_ask 會送 talk'
        elif tt=='kill':
            flag='OK'; why='npc.c 死亡時送 kill'
        elif tt=='deliver':
            flag='✗'; why='全專案沒有任何程式送出 deliver 事件'
        elif tt=='action':
            v, t = s.get('action_verb'), s.get('action_target')
            hit = any(v==av and (t is None or at is None or t==at) for av,at in action_verbs)
            flag = 'OK' if hit else '✗'; why = ('有房間送出' if hit else f'沒有任何房間送出 action({v},{t})')
        print(f"  {flag:2} S{stg}.{s['step']} {tt:8} {s.get('title','')[:14]:14} — {why}")

print("\n"+"="*70); print("B. 地點字串 vs 房間檔名（引擎用 strsrch 子字串比對）"); print("="*70)
for qid,(f,q) in Q.items():
    for stg,s in steps_of(q):
        loc = s.get('location')
        if not loc: continue
        base = loc.rstrip('/').split('/')[-1]
        ok = any(loc.endswith('/'+r) or loc.endswith('/'+r+'.c') for r in rooms)
        # strsrch semantic: loc must be a substring of base_name(env)
        sub = any(loc in ('/d/village/'+r) for r in rooms)
        if not sub: print(f"  ✗ {qid} S{stg}.{s['step']}  location={loc}  → 沒有任何房間的路徑包含此字串 (現有: {', '.join(sorted(rooms))})")

print("\n"+"="*70); print("C. NPC id 是否存在"); print("="*70)
refs = collections.defaultdict(set)
def walk(o, qid):
    if isinstance(o, dict):
        for k,v in o.items():
            if k in ('start_npc','target_npc','from_npc','target_mob') and isinstance(v,str): refs[v].add(f"{qid}.{k}")
            if k=='target_npc' and False: pass
            walk(v,qid)
    elif isinstance(o, list):
        for x in o: walk(x,qid)
for qid,(f,q) in Q.items(): walk(q,qid)
for r,where in sorted(refs.items()):
    if r in ('wolf',): continue
    ok = any(r.lower()==i or r.lower() in i or any(r.lower() in x for x in all_npc_ids) for i in all_npc_ids)
    print(f"  {'OK' if ok else '✗ '} {r:10} <- {sorted(where)[:3]}")

print("\n"+"="*70); print("D. 物品路徑與 require_item 別名"); print("="*70)
def items(o):
    if isinstance(o, dict):
        for k,v in o.items():
            if k in ('give_item','reissue_item') and isinstance(v,str): yield v
            if k=='items' and isinstance(v,list):
                for x in v: yield x
            yield from items(v)
    elif isinstance(o, list):
        for x in o: yield from items(x)
for qid,(f,q) in Q.items():
    for p in set(items(q)):
        print(f"  {'OK' if os.path.exists(R+p) else '✗ '} {p}  <- {qid}")
def reqs(o):
    if isinstance(o, dict):
        for k,v in o.items():
            if k in ('require_item','require_inventory','item') and isinstance(v,str): yield k,v
            yield from reqs(v)
    elif isinstance(o, list):
        for x in o: yield from reqs(x)
for qid,(f,q) in Q.items():
    for k,v in set(reqs(q)):
        if v not in alias_ok: print(f"  ✗ {qid}: {k}={v} 不在 has_required_item 白名單")

print("\n"+"="*70); print("E. JSON 欄位 vs 引擎實際讀取"); print("="*70)
used = collections.Counter()
def keys(o, path=''):
    if isinstance(o, dict):
        for k,v in o.items(): used[k]+=1; keys(v)
    elif isinstance(o, list):
        for x in o: keys(x)
for qid,(f,q) in Q.items(): keys(q)
cmdq = rd('cmds/cmd_quest.c')
for k in sorted(used):
    inng = ('"'+k+'"') in engine_src or ('"'+k+'"') in cmdq
    if not inng: print(f"  ✗ 欄位 \"{k}\" ({used[k]} 次) 引擎與 cmd_quest 都沒讀")
print("\n  --- 結算路徑檢查 ---")
for qid,(f,q) in Q.items():
    if q.get('stages'):
        last = q['stages'][-1]
        if 'rewards' in last and 'rewards' not in q and 'on_finish' not in last:
            print(f"  ✗ {qid}: 最後一個 stage 的獎勵寫在 stages[-1].rewards，但引擎只讀 q.rewards 與 stage.on_finish → 終局獎勵 {last['rewards']} 永遠不會發放")
print("\n  --- 動態 verb (無法靜態判定) ---", dyn)
