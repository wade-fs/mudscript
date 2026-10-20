// /tests/test_tier1_city.c
// Tier 1: 金石都城空間拓撲、三大一階道途與技能樹單元測試
// 驗證項目：
// 1. 九大分區目錄房間載入完整性與雙向拓撲連通性
// 2. 出村進城動線連通（黑石鋪 -> 南嶺官道 -> 金石南關 -> 中央廣場）
// 3. 都城環境機制（濁氣梯度指數、絕靈法網防衛、四關通行檢驗）
// 4. 三大一階門派道途（dao_initiate, wu_initiate, gong_initiate）專屬技能樹註冊
// 5. 轉職任務與獎勵結算（class_grant、烏木尺、黑鐵腰牌、引氣訣、清心散、身分緩衝信物）

inherit "/std/test_case.c";

#include "/include/globals.h"

void run_tests(object me) {
    start_test("Tier 1: 金石都城空間拓撲、三大一階道途與技能樹驗證");

    // ── 1. 守護進程載入檢驗 ──────────────────────────────────
    object city_d = load_object(CITY_D);
    assert_true(objectp(city_d), "金石都城環境守護進程 (CITY_D) 必須成功載入");

    object q_engine = load_object(QUEST_ENGINE_D);
    assert_true(objectp(q_engine), "任務引擎 (QUEST_ENGINE_D) 必須成功載入");

    object sk_d = load_object(SKILL_D);
    assert_true(objectp(sk_d), "技能守護進程 (SKILL_D) 必須成功載入");

    // ── 2. 十字骨架與核心房間載入驗證 ─────────────────────────
    string *core_rooms = ({
        "/d/city/outer/south_road.c",
        "/d/city/outer/farmland_w.c",
        "/d/city/outer/irrigation.c",
        "/d/city/outer/graveyard.c",
        "/d/city/outer/post_depot.c",

        "/d/city/gate/gate_south.c",
        "/d/city/gate/gate_south_inn.c",
        "/d/city/gate/gate_north.c",
        "/d/city/gate/gate_plaza.c",
        "/d/city/gate/gate_inn.c",
        "/d/city/gate/gate_warehouse.c",
        "/d/city/gate/gate_east.c",
        "/d/city/gate/gate_west.c",

        "/d/city/wall/wall_path_s.c",
        "/d/city/wall/wall_path_n.c",
        "/d/city/wall/wall_path_e.c",
        "/d/city/wall/wall_path_w.c",
        "/d/city/wall/wall_tower_n.c",
        "/d/city/wall/wall_tower_s.c",
        "/d/city/wall/wall_tower_e.c",
        "/d/city/wall/wall_tower_w.c",
        "/d/city/wall/moat.c",

        "/d/city/center/square.c",
        "/d/city/center/yamen.c",
        "/d/city/center/yamen_archive.c",
        "/d/city/center/yamen_prison.c",
        "/d/city/center/granary.c",
        "/d/city/center/academy.c",
        "/d/city/center/clinic.c",
        "/d/city/center/bank.c",
        "/d/city/center/pawnshop.c",
        "/d/city/center/black_alley.c",
        "/d/city/center/inn_main.c",
        "/d/city/center/post_station.c",

        "/d/city/west/dao_gate.c",
        "/d/city/west/dao_hall.c",
        "/d/city/west/dao_observatory.c",
        "/d/city/west/dao_roof.c",
        "/d/city/west/dao_quiet.c",

        "/d/city/east/wu_gate.c",
        "/d/city/east/wu_plaza.c",
        "/d/city/east/wu_arena.c",
        "/d/city/east/wu_hall.c",
        "/d/city/east/wu_armory.c",
        "/d/city/east/wu_barracks.c",

        "/d/city/north/gong_gate.c",
        "/d/city/north/gong_hall.c",
        "/d/city/north/gong_registry.c",
        "/d/city/north/gong_forge.c",
        "/d/city/north/gong_wood.c",
        "/d/city/north/gong_stone.c",
        "/d/city/north/gong_leather.c",
        "/d/city/north/gong_alchemy.c",
        "/d/city/north/gong_fireworks.c",

        "/d/city/south/market_special.c",
        "/d/city/south/shanghui_hq.c",
        "/d/city/south/caravan_yard.c",
        "/d/city/south/warehouse_shang.c",
        "/d/city/south/yard_material.c",
        "/d/city/south/grain_market.c",
        "/d/city/south/canal.c",
        "/d/city/south/warehouse_grain.c",

        "/d/city/under/black_market.c",
        "/d/city/under/canal_hub.c",
        "/d/city/under/drain_gate.c",
        "/d/city/under/shang_secret.c",
        "/d/city/under/ruins_hall.c"
    });

    foreach (string r_path in core_rooms) {
        object rob = load_object(r_path);
        assert_true(objectp(rob), sprintf("都城房間必須載入成功: %s", r_path));
        if (rob) {
            assert_true(strlen(rob->query_short()) > 0, sprintf("房間標題不可為空: %s", r_path));
            assert_true(strlen(rob->query_long()) > 0, sprintf("房間描述不可為空: %s", r_path));
            mapping exits = rob->query_exits();
            assert_true(mapp(exits) && sizeof(exits) > 0, sprintf("房間必須具備有效出口: %s", r_path));
        }
    }

    // ── 3. 出村進城雙線拓撲連通性檢驗 (450里東線盤木道 & 420里西線重石棧道) ──
    object v_square = load_object("/d/village/square.c");
    assert_true(objectp(v_square), "黑石鋪街市必須載入");
    mapping v_exits = v_square->query_exits();
    assert_equal("/d/routes/blackstone_pass.c", v_exits["northeast"], "黑石鋪街市東北方出口必須通向東線起點【黑石關】");
    assert_equal("/d/routes/west_gorge_entry.c", v_exits["northwest"], "黑石鋪街市西北方出口必須通向西線起點【落龍西谷棧道口】");

    object s_road = load_object("/d/city/outer/south_road.c");
    mapping r_exits = s_road->query_exits();
    assert_equal("/d/routes/forest_landslide.c", r_exits["southeast"], "南嶺官道匯流口東南方必須接東線【南嶺林海官道】");
    assert_equal("/d/routes/stone_highway_pavilion.c", r_exits["southwest"], "南嶺官道匯流口西南方必須接西線【西南條石馳道】");
    assert_equal("/d/city/gate/gate_south.c", r_exits["north"], "南嶺官道北方必須直達金石南關");

    object c_square = load_object("/d/city/center/square.c");
    mapping c_exits = c_square->query_exits();
    assert_equal("/d/city/west/dao_gate.c", c_exits["west"], "中央廣場向西直通宣道司");
    assert_equal("/d/city/east/wu_gate.c", c_exits["east"], "中央廣場向東直通鎮武軍鎮");
    assert_equal("/d/city/north/gong_gate.c", c_exits["north"], "中央廣場向北直通百工總會");
    assert_equal("/d/city/south/market_special.c", c_exits["south"], "中央廣場向南直通專材長街");

    // ── 4. 都城環境機制 (濁氣與法網) ──────────────────────────
    assert_equal(100, city_d->query_turbidity_index("/d/city/center/square.c"), "市井核心濁氣指數應為 100%");
    assert_equal(100, city_d->query_turbidity_index("/d/city/south/market_special.c"), "商貿區濁氣指數應為 100%");
    assert_equal(45, city_d->query_turbidity_index("/d/city/west/dao_hall.c"), "宣道司道統區濁氣指數應為 45%");
    assert_equal(45, city_d->query_turbidity_index("/d/city/north/gong_hall.c"), "百工總會道統區濁氣指數應為 45%");
    assert_equal(15, city_d->query_turbidity_index("/d/city/outer/farmland_w.c"), "城外近郊濁氣指數應為 15%");
    assert_equal(5, city_d->query_turbidity_index("/d/city/under/black_market.c"), "城下暗渠濁氣指數應為 5%");

    assert_equal(1, city_d->is_spirit_sealed_grid("/d/city/center/square.c"), "市井中央應受絕靈法網覆蓋");
    assert_equal(1, city_d->is_spirit_sealed_grid("/d/city/west/dao_hall.c"), "宣道司正堂應受絕靈法網覆蓋");
    assert_equal(0, city_d->is_spirit_sealed_grid("/d/city/outer/farmland_w.c"), "城外近郊不應受絕靈法網覆蓋");
    assert_equal(0, city_d->is_spirit_sealed_grid("/d/city/under/black_market.c"), "城下暗渠不應受絕靈法網覆蓋");

    // 濁氣淨化驗證
    me->set("turbidity", 60);
    city_d->cleanse_turbidity(me, 20);
    assert_equal(40, me->query("turbidity"), "淨化 20 點濁氣後應剩餘 40 點");
    city_d->cleanse_turbidity(me, 50);
    assert_equal(0, me->query("turbidity"), "超量淨化後濁氣最低歸零");

    // ── 5. 門派技能樹與技能守護進程註冊驗證 ───────────────────
    mapping all_sk = sk_d->query_all_skills();
    assert_true(mapp(all_sk["dao_tuna"]), "法道專屬技能 dao_tuna 必須註冊");
    assert_true(mapp(all_sk["dao_jiefa"]), "法道專屬技能 dao_jiefa 必須註冊");
    assert_true(mapp(all_sk["wu_cuigu"]), "力道專屬技能 wu_cuigu 必須註冊");
    assert_true(mapp(all_sk["wu_fuhu"]), "力道專屬技能 wu_fuhu 必須註冊");
    assert_true(mapp(all_sk["gong_analysis"]), "物道專屬技能 gong_analysis 必須註冊");
    assert_true(mapp(all_sk["gong_qiaojin"]), "物道專屬技能 gong_qiaojin 必須註冊");

    // 門派技能入門發放
    sk_d->grant_starter_class_skills(me, "dao_initiate");
    assert_true(me->query_skill("dao_tuna") >= 31, "法道入門應獲得等級 31 基礎吐納");
    assert_true(me->query_skill("dao_jiefa") >= 31, "法道入門應獲得等級 31 借法印訣");

    sk_d->grant_starter_class_skills(me, "wu_initiate");
    assert_true(me->query_skill("wu_cuigu") >= 31, "力道入門應獲得等級 31 鐵砂淬骨");
    assert_true(me->query_skill("wu_fuhu") >= 31, "力道入門應獲得等級 31 伏虎重拳");

    sk_d->grant_starter_class_skills(me, "gong_initiate");
    assert_true(me->query_skill("gong_analysis") >= 31, "物道入門應獲得等級 31 物性辨析");
    assert_true(me->query_skill("gong_qiaojin") >= 31, "物道入門應獲得等級 31 百工巧勁");

    // ── 6. 轉職任務與獎勵結算機制驗證 ─────────────────────────
    assert_true(mapp(q_engine->query_quest_def("tier1_dao_initiation")), "法道轉職任務 tier1_dao_initiation 必須成功載入");
    assert_true(mapp(q_engine->query_quest_def("tier1_wu_initiation")), "力道轉職任務 tier1_wu_initiation 必須成功載入");
    assert_true(mapp(q_engine->query_quest_def("tier1_gong_initiation")), "物道轉職任務 tier1_gong_initiation 必須成功載入");

    // 驗證獎勵發放 class_grant
    mapping test_rw = ([
        "class_grant": "gong_initiate",
        "item": "/clone/tool/gong_ebony_ruler.c",
        "exp": 1200
    ]);
    q_engine->award_rewards(me, test_rw, "tier1_gong_initiation");
    assert_equal("gong_initiate", me->query("class"), "結算獎勵後玩家身分必須正確轉為 gong_initiate");
    assert_true(present("ebony ruler", me) || present("烏木尺", me), "玩家必須成功取得天工烏木尺信物");

    // ── 7. 關鍵道具實例化驗證 ─────────────────────────────────
    object book = clone_object("/clone/book/dao_basic_manual.c");
    assert_true(objectp(book), "周虛微茫引氣訣必須可複製");
    if (book) destruct(book);

    object belt = clone_object("/clone/armour/wu_iron_belt.c");
    assert_true(objectp(belt), "八方黑鐵腰牌束帶必須可複製");
    if (belt) destruct(belt);

    object pill = clone_object("/clone/item/turbidity_pill.c");
    assert_true(objectp(pill), "清心散必須可複製");
    if (pill) destruct(pill);

    object mirror = clone_object("/clone/item/dao_mirror.c");
    assert_true(objectp(mirror), "渾天黃銅鏡必須可複製");
    if (mirror) destruct(mirror);

    object tok_acad = clone_object("/clone/item/academy_token.c");
    assert_true(objectp(tok_acad), "學塾白鹿青衿必須可複製");
    if (tok_acad) destruct(tok_acad);

    object tok_caravan = clone_object("/clone/item/caravan_token.c");
    assert_true(objectp(tok_caravan), "車馬行短褐腰牌必須可複製");
    if (tok_caravan) destruct(tok_caravan);

    object tok_clinic = clone_object("/clone/item/clinic_token.c");
    assert_true(objectp(tok_clinic), "杏林藥囊腰牌必須可複製");
    if (tok_clinic) destruct(tok_clinic);

    // ── 8. 地圖系統繪製驗證 ───────────────────────────────────
    object map_d = load_object("/secure/map_d.c");
    assert_true(objectp(map_d), "地圖守護進程 /secure/map_d.c 必須載入");
    string world_map = map_d->draw_world_map(me);
    assert_true(strsrch(world_map, "金石府城") != -1, "宏觀世界地圖必須包含金石府城");
    assert_true(strsrch(world_map, "黑石鋪") != -1, "宏觀世界地圖必須包含黑石鋪");

    string city_map = map_d->draw_city_map(me);
    assert_true(strsrch(city_map, "金石都城") != -1, "都城地圖必須包含標題");
    assert_true(strsrch(city_map, "中央青石廣場") != -1, "都城地圖必須包含中央青石廣場");
    assert_true(strsrch(city_map, "宣道司") != -1, "都城地圖必須包含宣道司");
    assert_true(strsrch(city_map, "鎮武軍鎮") != -1, "都城地圖必須包含鎮武軍鎮");
    assert_true(strsrch(city_map, "百工總會") != -1, "都城地圖必須包含百工總會");

    string under_map = map_d->draw_under_map(me);
    assert_true(strsrch(under_map, "太古暗渠") != -1, "地下地圖必須包含太古暗渠");
    assert_true(strsrch(under_map, "地下鬼市") != -1, "地下地圖必須包含地下鬼市");

    string village_map = map_d->draw_village_map(me);
    assert_true(strsrch(village_map, "黑石鋪") != -1, "村落小地圖必須包含黑石鋪");

    // ── 9. Tier 1 NPC 名冊全數載入、屬性原型與別名防撞驗證 ──────
    string *tier1_npcs = ({
        "/clone/npc/gate_north_hanqing.c",
        "/clone/npc/gate_south_inn_laoliu.c",
        "/clone/npc/gate_inn_laopi.c",
        "/clone/npc/wall_tower_n_yanmu.c",
        "/clone/npc/yamen_zhou.c",
        "/clone/npc/center_wenchengjing.c",
        "/clone/npc/yamen_prison_tieliaozhang.c",
        "/clone/npc/granary_liubingzhong.c",
        "/clone/npc/center_teacher_lu.c",
        "/clone/npc/post_station_maqianli.c",
        "/clone/npc/inn_main_qianbuhuan.c",
        "/clone/npc/center_doctor_bai.c",
        "/clone/npc/center_pawn_jia.c",
        "/clone/npc/dao_xuanji.c",
        "/clone/npc/dao_xingyuan.c",
        "/clone/npc/wu_bashan.c",
        "/clone/npc/wu_zhaomeng.c",
        "/clone/npc/wu_referee.c",
        "/clone/npc/gong_gate_tiechigong.c",
        "/clone/npc/gong_ouyang.c",
        "/clone/npc/gong_mochui.c",
        "/clone/npc/gong_luchangsheng.c",
        "/clone/npc/gong_stone_hanlaodiao.c",
        "/clone/npc/gong_leather_wenniangzi.c",
        "/clone/npc/gong_alchemy_sunxiansheng.c",
        "/clone/npc/south_canal_caotiemao.c",
        "/clone/npc/outer_farmland_w_zhaodingtian.c",
        "/clone/npc/outer_post_depot_laowang.c",
        "/clone/npc/south_qianbaichuan.c",
        "/clone/npc/city_gate_guard.c",
        "/clone/npc/gate_south_taxofficer.c",
        "/clone/npc/gate_south_runner.c",
        "/clone/npc/south_yard_material_foreman.c",
        "/clone/npc/gate_east_taxchief.c",
        "/clone/npc/gate_west_helmsman.c",
        "/clone/npc/gate_west_inspector.c",
        "/clone/npc/gate_plaza_deputy.c",
        "/clone/npc/gate_warehouse_assessor.c",
        "/clone/npc/wall_tower_s_archerymaster.c",
        "/clone/npc/wall_tower_e_beaconchief.c",
        "/clone/npc/wall_tower_w_navalofficer.c",
        "/clone/npc/moat_angler.c",
        "/clone/npc/yamen_magistrate.c",
        "/clone/npc/square_storyteller.c",
        "/clone/npc/square_watchman.c",
        "/clone/npc/bank_chief.c",
        "/clone/npc/black_alley_gatekeeper.c",
        "/clone/npc/dao_tong.c",
        "/clone/npc/south_grain_guildhead.c",
        "/clone/npc/south_warehouse_grain_scale.c",
        "/clone/npc/outer_irrigation_engineer.c",
        "/clone/npc/outer_graveyard_keeper.c",
        "/clone/npc/gong_fireworks_master.c",
        "/clone/npc/gong_registry_clerk.c",
        "/clone/npc/shanghui_hq_steward.c",
        "/clone/npc/market_special_buyer.c",
        "/clone/npc/caravan_yard_manager.c",
        "/clone/npc/caravan_yard_biaotou.c",
        "/clone/npc/warehouse_shang_chief.c",
        "/clone/npc/wu_gate_squadleader.c",
        "/clone/npc/wu_plaza_colonel.c",
        "/clone/npc/wu_hall_enforcer.c",
        "/clone/npc/wu_armory_quartermaster.c",
        "/clone/npc/wu_barracks_veteran.c",
        "/clone/npc/under_black_market_broker.c",
        "/clone/npc/under_canal_hub_ferryman.c",
        "/clone/npc/under_drain_gate_diver.c",
        "/clone/npc/yamen_prison_zhaodegui.c",
        "/clone/npc/yamen_prison_hubaihu.c"
    });

    foreach (string npc_path in tier1_npcs) {
        object nob = clone_object(npc_path);
        assert_true(objectp(nob), sprintf("Tier 1 NPC 必須成功複製: %s", npc_path));
        if (nob) {
            assert_true(nob->query("level") > 0, sprintf("NPC 等級必須大於 0: %s", npc_path));
            assert_true(nob->query("max_kee") > 0 && nob->query("max_sen") > 0 && nob->query("max_sp") > 0,
                        sprintf("NPC 三柱上限必須正確初始化: %s", npc_path));
            assert_true(strlen(nob->query("archetype")) > 0, sprintf("NPC 必須設定屬性原型: %s", npc_path));
            // 驗證防撞：所有 Tier 1 NPC 不得回應裸單字百家姓 "zhao", "mo", "jia", "lu", "qian", "han"
            assert_equal(0, nob->id("zhao"), sprintf("NPC 不應回應單字姓 zhao: %s", npc_path));
            assert_equal(0, nob->id("mo"), sprintf("NPC 不應回應單字姓 mo: %s", npc_path));
            assert_equal(0, nob->id("jia"), sprintf("NPC 不應回應單字姓 jia: %s", npc_path));
            assert_equal(0, nob->id("lu"), sprintf("NPC 不應回應單字姓 lu: %s", npc_path));
            assert_equal(0, nob->id("qian"), sprintf("NPC 不應回應單字姓 qian: %s", npc_path));
            assert_equal(0, nob->id("han"), sprintf("NPC 不應回應單字姓 han: %s", npc_path));
            destruct(nob);
        }
    }

    // ── 10. 四大核心支柱驗證：唯一路網、權力會審、六縣30天自走時鐘、技能四維解耦 ──

    // (1) 唯一交通路網模型 (ROUTE_SEGMENTS) 與黑石鋪 450 里 / 420 里雙路線
    mapping all_segs = city_d->query_all_route_segments();
    assert_equal(12, sizeof(all_segs), "全域標準交通路段表必須包含 12 條核心路段");
    mapping comp_routes = city_d->query_composite_routes("blackstone", "city");
    assert_equal(450, comp_routes["east_panmu_route"]["total_distance_li"], "黑石鋪至府城東線（經盤木林道）總里程應為 450 里");
    assert_equal(1, comp_routes["east_panmu_route"]["heavy_wagon_allowed"], "黑石鋪至府城東線（盤木線）允許通行重型大車");
    assert_equal(420, comp_routes["west_zhongshi_route"]["total_distance_li"], "黑石鋪至府城西線（經重石河谷棧道）總里程應為 420 里");
    assert_equal(0, comp_routes["west_zhongshi_route"]["heavy_wagon_allowed"], "黑石鋪至府城西線（落龍西谷棧道）禁止重型大車通行");

    // (2) 歷史法統、軍令雙印合符與三方會審機制
    mapping border_auth = city_d->check_military_order_auth("border_patrol", ({ "junzhen_tiger_tally" }));
    assert_equal(1, border_auth["authorized"], "關外邊防盤查僅需軍鎮虎符即可授權");
    mapping city_deploy_fail = city_d->check_military_order_auth("city_deployment", ({ "junzhen_tiger_tally" }));
    assert_equal(0, city_deploy_fail["authorized"], "單憑軍鎮虎符不得擅自調兵入內城或查抄大宗家產");
    mapping city_deploy_ok = city_d->check_military_order_auth("city_deployment", ({ "yamen_seal", "junzhen_tiger_tally", "supply_warrant" }));
    assert_equal(1, city_deploy_ok["authorized"], "集齊府衙官印、軍鎮虎符與後勤餉票三印合符方可調兵執法");

    mapping tribunal_res = city_d->conduct_tripartite_tribunal("blackstone_smuggling", ({ "miner_thumbprints", "garrison_bribe_ledger", "crucible_bing_7" }));
    assert_equal("convicted", tribunal_res["verdict"], "三方會審物證確鑿時應裁定收押定罪");
    assert_equal(30, tribunal_res["asset_split"]["granary"], "罰沒資產三成應充入常平倉");
    assert_equal(40, tribunal_res["asset_split"]["military_pay"], "罰沒資產四成應折抵邊軍欠餉");

    // (3) 六縣與黑石鋪 30 天無主角介入之自主演進時間線 (Autonomous 30-Day Clocks)
    object ws_d = load_object(WORLD_STATE_D);
    ws_d->init_county_clocks();
    mapping qh_d1 = ws_d->query_county_status("qinghe");
    assert_equal(1, qh_d1["stage"], "青河縣 Day 1 應處於第 1 階段（初兆）");
    mapping qh_d10 = ws_d->advance_county_day("qinghe", 9); // Day 10
    assert_equal(2, qh_d10["stage"], "青河縣無主角干預至 Day 10 應自主升級至第 2 階段（爭水械鬥）");
    mapping qh_d20 = ws_d->advance_county_day("qinghe", 10); // Day 20
    assert_equal(3, qh_d20["stage"], "青河縣無主角干預至 Day 20 應自主進入第 3 階段（潰漫封鎖、藥價告急）");
    assert_equal(160, qh_d20["price_pct"], "青河縣第 3 階段爆發期藥糧價格指數應達 160%");
    mapping qh_d26 = ws_d->advance_county_day("qinghe", 6); // Day 26
    assert_equal(4, qh_d26["stage"], "青河縣無主角干預至 Day 26 應進入第 4 階段（地方自行妥協與後遺症）");
    assert_equal(1, qh_d26["aftermath_triggered"], "第 4 階段應留下地方妥協之次生後遺症標記");

    // (4) 技能四維解耦：道途 (Path) ≠ 實際能力 (Skill) ≠ 專業資格 (Qualification) ≠ 門派組織 (Organization)
    me->revoke_qualification("lic_apothecary");
    me->set_skill("gong_analysis", 40);
    me->set_skill("gong_xingzhen", 45);
    mapping act_unlicensed = sk_d->check_professional_action(me, "prescribe_medicine");
    assert_equal("unlicensed_skill", act_unlicensed["status"], "懂得辨藥行針卻無杏林行醫資格時，應判定為無照私醫 (懂技術 != 有資格開藥)");

    me->set_skill("gong_analysis", 0);
    me->set_skill("gong_xingzhen", 0);
    me->set_skill("alchemy", 0);
    me->grant_qualification("lic_apothecary", 1);
    mapping act_no_skill = sk_d->check_professional_action(me, "prescribe_medicine");
    assert_equal("licensed_no_skill", act_no_skill["status"], "持有行醫資格卻未修習醫理功法時，應判定為空有資格無從下手 (有資格 != 必然修得功法)");

    me->set_skill("gong_analysis", 40);
    me->set_skill("gong_xingzhen", 45);
    mapping act_both = sk_d->check_professional_action(me, "prescribe_medicine");
    assert_equal("qualified_practitioner", act_both["status"], "兼具醫理技能與行醫資格時，方可合法坐堂開方");

    // 驗證加入百工總會享有工坊存取權，但不會自動學會高階分支技能樹
    me->set_skill("gong_yingli", 0);
    me->set_skill("gong_cuihuo", 0);
    me->set_skill("gong_xingzhen", 0);
    me->set_skill("gong_fengdu", 0);
    me->set_skill("gong_jiguan", 0);
    me->set_skill("gong_feizhua", 0);
    me->join_organization("org_baigong", "百工總會註冊學徒");
    mapping fac_check = sk_d->check_org_facility_access(me, "org_baigong", "/d/city/north/gong_forge.c");
    assert_equal(1, fac_check["access"], "加入百工總會後應享有千錘地爐坊設施存取權");
    assert_equal(0, fac_check["advanced_skills_unlocked"], "加入行會不等於自動掌握整條高階技能樹");

    // ── 11. 《跨系統第一輪審核》與《Tier 1 世界運作模型 v0.1》新增驗證 ──

    // (5) P0-2 & OPEN-02(B) 六縣多起點地方傳承等效規則與 18 處分舵考場驗證
    string *all_counties = ({ "qinghe", "liefan", "panmu", "zhenfeng", "zhuoshui", "zhongshi" });
    string *all_paths = ({ "fa", "li", "wu" });
    foreach (string cid in all_counties) {
        foreach (string p in all_paths) {
            mapping ceq = sk_d->check_county_qualification_equivalence(cid, p);
            assert_equal(1, ceq["equivalent"], sprintf("六縣分舵 (%s/%s) 必須提供等效初階資格入口", cid, p));
            assert_equal("RULE", ceq["canon_rule"], sprintf("六縣分舵 (%s/%s) 規則狀態應為 RULE", cid, p));
            assert_true(strlen(ceq["lic_id"]) > 0 && strlen(ceq["org_id"]) > 0 && strlen(ceq["branch_id"]) > 0,
                        sprintf("六縣分舵 (%s/%s) 必須具備完整 lic_id / org_id / branch_id 結構", cid, p));
        }
    }

    // 驗證地方考取資格與府城立籍等效、分舵場地直通、以及府城總舵「掛單轉錄」機制
    object county_student = clone_object("/std/user.c");
    int init_ok = sk_d->grant_county_initiation(county_student, "panmu", "wu");
    assert_equal(1, init_ok, "盤木縣【物】道地方啟蒙應成功執行");
    assert_equal(1, county_student->query_qualification("lic_master_artisan"), "盤木縣考取資格應核發等效百工匠籍 (lic_master_artisan)");
    assert_equal("天工木作工棚（百工機巧分舵）", county_student->query_qualification_issuer("lic_master_artisan"), "資格核發機構應記錄為盤木天工木作工棚");
    assert_true(county_student->query_skill("gong_analysis") >= 31 && county_student->query_skill("gong_qiaojin") >= 31, "地方啟蒙應習得 Lv.31 基礎物道技能");

    // 持六縣資格入府城即享正式立籍豁免（不受 72 小時流民驅逐令限制）
    mapping county_res = city_d->check_residency_mandate(county_student, 200);
    assert_equal("formal_resident", county_res["status"], "持六縣等效資格入城應直接視為正式立籍居民 (formal_resident)");

    // 分舵成員可直接存取本縣工坊，但未掛單轉錄前不得直接調用府城總部千錘地爐
    mapping branch_fac = sk_d->check_org_facility_access(county_student, "org_baigong", "/d/counties/panmu/carpentry_shed.c");
    assert_equal(1, branch_fac["access"], "盤木分舵成員應可直接存取盤木天工木作工棚");
    mapping hq_fac_before = sk_d->check_org_facility_access(county_student, "org_baigong", "/d/city/north/gong_forge.c");
    assert_equal(0, hq_fac_before["access"], "地方分舵成員未辦理掛單轉錄前，不得直接調用府城總舵千錘地爐");
    assert_equal("requires_hq_registration", hq_fac_before["status"], "未掛單轉錄應回傳 requires_hq_registration 狀態");

    mapping reg_res = sk_d->register_at_headquarters(county_student, "org_baigong");
    assert_equal(1, reg_res["registered"], "地方分舵成員赴府城總舵辦理掛單轉錄應成功");
    mapping hq_fac_after = sk_d->check_org_facility_access(county_student, "org_baigong", "/d/city/north/gong_forge.c");
    assert_equal(1, hq_fac_after["access"], "完成總舵掛單轉錄後應解鎖府城總部千錘地爐存取權");
    destruct(county_student);

    // 驗證 /std/county_room.c、/std/route_room.c 與 /daemon/travel_d.c 基底架構
    object c_room_base = load_object(COUNTY_ROOM_OB);
    assert_true(objectp(c_room_base), "六縣房間基底類別 (/std/county_room.c) 必須成功載入");
    c_room_base->set_county("qinghe");
    c_room_base->set_qual_path("wu");
    assert_true(c_room_base->query_local_price_pct() > 0, "county_room 必須能從 WORLD_STATE_D 讀取當前縣域物價指數");
    assert_true(strsrch(c_room_base->query_long(), "青河洗藥總坊") != -1, "設定 qual_path 之 county_room 描述應顯示地方傳承入口資訊");

    object r_room_base = load_object(ROUTE_ROOM_OB);
    assert_true(objectp(r_room_base), "標準路段節點房間基底類別 (/std/route_room.c) 必須成功載入");
    r_room_base->set_route_segment("seg_blackstone_panmu");
    assert_true(strsrch(r_room_base->query_long(), "虎跳峽林道") != -1, "route_room 描述應自動整合 CITY_D 標準路段資訊");

    object travel_d = load_object(TRAVEL_D);
    assert_true(objectp(travel_d), "全域路網通行守護進程 (/daemon/travel_d.c) 必須成功載入");
    mapping tr_wagon_fail = travel_d->check_segment_traversal(me, "seg_blackstone_zhongshi", "heavy_wagon");
    assert_equal(0, tr_wagon_fail["allowed"], "落龍西谷棧道應禁止重型大車通行");
    assert_equal("heavy_wagon_forbidden", tr_wagon_fail["reason"], "禁行原因應為 heavy_wagon_forbidden");

    mapping tr_horse_fail = travel_d->check_segment_traversal(me, "seg_city_qinghe_water", "fast_horse");
    assert_equal(0, tr_horse_fail["allowed"], "青河漕運水路應禁止騎乘快馬");

    me->set_temp("override_season", "summer");
    mapping tr_summer_block = travel_d->check_segment_traversal(me, "seg_city_qinghe_water", "water_barge");
    assert_equal(0, tr_summer_block["allowed"], "品物夏歲洪峰期間青河漕運水路應季節性封航");
    assert_equal("seasonal_block", tr_summer_block["reason"], "封航原因應為 seasonal_block");

    me->set_temp("override_season", "autumn");
    int old_li = me->query("travel_distance_li");
    mapping tr_ok = travel_d->record_segment_traversal(me, "seg_blackstone_panmu", "foot");
    assert_equal(1, tr_ok["allowed"], "虎跳峽林道秋季步卒應允許通行");
    assert_equal(old_li + 190, me->query("travel_distance_li"), "通行虎跳峽林道後累計跋涉里程應增加 190 里");
    me->set_temp("override_season", 0);

    // (6) P0-3 路段表標準欄位 (one_way, canon_status, travel_mode, seasonal_block)
    mapping seg_bp = city_d->query_route_segment("seg_blackstone_panmu");
    assert_equal(0, seg_bp["one_way"], "虎跳峽林道應為雙向可逆路段 (one_way == 0)");
    assert_equal("CANON", seg_bp["canon_status"], "虎跳峽林道應標記為 CANON 正典狀態");

    // (7) P0-4 證據狀態五欄模型與證明力邊界 (lead_only / corroborating / conclusive)
    mapping ev_broken = city_d->evaluate_evidence_probative_value("under_canal_deed", 0, 1);
    assert_equal("lead_only", ev_broken["tier"], "暗渠底單若保管鏈有瑕疵，僅能作為調查線索 (lead_only)，不可自動補正真偽");
    mapping ev_single = city_d->evaluate_evidence_probative_value("detonator_serial_ledger", 1, 1);
    assert_equal("corroborating", ev_single["tier"], "單一內部軍需簽領簿經認證後為間接佐證 (corroborating)，須與跨機構實物互鎖");
    mapping ev_conclusive = city_d->evaluate_evidence_probative_value("crucible_bing_7", 1, 1);
    assert_equal("conclusive", ev_conclusive["tier"], "丙字柒號坩堝具物理殘留、完整保管鏈與雙重認證時為核心實證 (conclusive)");

    // (8) P0-5 權力機構認證性質與專職邊界 (宣道司專業鑑定 vs 行政裁決、文承敬、陳鎮山)
    mapping auth_xd = city_d->query_power_authority("xuandaosi");
    assert_equal("technical_forensic_opinion", auth_xd["cert_nature"], "宣道司勘驗結論應界定為專業技術鑑定意見，而非直接行政司法裁決");
    mapping auth_wcj = city_d->query_power_authority("wen_chengjing");
    assert_equal("archival_document_notarization", auth_wcj["cert_nature"], "案牘主簿文承敬職權應為官方文書比對公證");

    // (9) 壓力測試節點 1 (Ch.39–46)：72 小時三日通牒與三條緩衝路徑精確法律定義
    object fresh_visitor = clone_object("/std/user.c");
    mapping res_48h = city_d->check_residency_mandate(fresh_visitor, 48);
    assert_equal("initial_72h_window", res_48h["status"], "入城 48 小時無憑證者應處於 72 小時臨時居留登錄期限內");
    mapping res_80h = city_d->check_residency_mandate(fresh_visitor, 80);
    assert_equal("unregistered_vagrant", res_80h["status"], "入城逾 72 小時未獲機構擔保者應列為無籍流民");
    fresh_visitor->set_temp("residency_buffer", "academy");
    mapping res_buf = city_d->check_residency_mandate(fresh_visitor, 200);
    assert_equal("buffered_temporary", res_buf["status"], "持蒙學塾保書者於 200 小時仍在 +14 天 (408h) 正式立籍考核寬限期內");
    destruct(fresh_visitor);

    // (10) 壓力測試節點 3 (Ch.68–76)：通寶分號信用凍結邊界與人為操控核驗
    mapping freeze_bill = city_d->evaluate_credit_freeze_impact("inter_county_bill");
    assert_equal(1, freeze_bill["frozen"], "通寶信用凍結期間，跨縣飛錢匯票應停止異地兌付");
    mapping freeze_cash = city_d->evaluate_credit_freeze_impact("cash_copper_silver");
    assert_equal(0, freeze_cash["frozen"], "通寶信印非唯一法定貨幣，民間現銅現銀買賣不受票據凍結影響");
    mapping manip_check = city_d->verify_credit_freeze_manipulation(1, 1);
    assert_equal(1, manip_check["proven_manipulation"], "同時比對通寶準備金底冊與南關押銀入城稅單即可證實人為惡意操控");

    // (11) 壓力測試節點 4 (Ch.79–82)：卷尾破境與 Tier 1→Tier 2 門檻四維分離
    me->set_level(50);
    me->set_skill("gong_analysis", 60); // 尚未達 Lv.100
    me->set("tier2_admission_token", 0);
    mapping t1_state = sk_d->evaluate_tier1_completion_state(me);
    assert_equal(1, t1_state["realm_breakthrough"], "角色達 Lv.50 完成肉身／心神破障");
    assert_equal(0, t1_state["skill_mastery"], "破障至 Lv.50 不等於技能自動滿值 Lv.100");
    assert_equal(0, t1_state["ready_for_tier2_trial"], "未取得名山宗門考核令前，僅憑 Lv.50 破障尚未完成二階山門大考報名閉環");
    me->set("tier2_admission_token", 1);
    mapping t1_ready = sk_d->evaluate_tier1_completion_state(me);
    assert_equal(1, t1_ready["ready_for_tier2_trial"], "兼具破障、社會專業資格與宗門考核令後方可進入 Tier 2 山門大考");

    // ── 12. Batch 1：南向雙路網 (8節點)、盤木縣 (14房)、重石縣 (14房) 與 6 處考場驗證 ──
    string *batch1_route_rooms = ({
        "/d/routes/blackstone_pass.c",
        "/d/routes/tiger_leap_gorge.c",
        "/d/routes/panmu_post_approach.c",
        "/d/routes/forest_sea_post.c",
        "/d/routes/forest_landslide.c",
        "/d/routes/west_gorge_entry.c",
        "/d/routes/cliff_broken_plank.c",
        "/d/routes/stone_highway_pavilion.c"
    });
    foreach (string rr_path in batch1_route_rooms) {
        object rrob = load_object(rr_path);
        assert_true(objectp(rrob), sprintf("南向雙路網節點房間必須載入成功: %s", rr_path));
        if (rrob) {
            assert_true(strlen(rrob->query_route_segment()) > 0, sprintf("路網節點必須綁定標準路段 ID: %s", rr_path));
            assert_true(sizeof(rrob->query_exits()) >= 2, sprintf("路網節點必須具備雙向連通出口: %s", rr_path));
        }
    }

    string *panmu_rooms = ({
        "/d/counties/panmu/south_gate.c",
        "/d/counties/panmu/market.c",
        "/d/counties/panmu/yamen.c",
        "/d/counties/panmu/pawnshop.c",
        "/d/counties/panmu/post_inn.c",
        "/d/counties/panmu/carpentry_shed.c",
        "/d/counties/panmu/tannery_mill.c",
        "/d/counties/panmu/mountain_shrine.c",
        "/d/counties/panmu/hunter_lodge.c",
        "/d/counties/panmu/north_gate.c",
        "/d/counties/panmu/qingsong_hamlet.c",
        "/d/counties/panmu/qingsong_traps.c",
        "/d/counties/panmu/daoying_stream.c",
        "/d/counties/panmu/fir_logging_line.c"
    });
    assert_equal(14, sizeof(panmu_rooms), "盤木縣必須包含完整 14 間實體房間");
    foreach (string pm_path in panmu_rooms) {
        object pmob = load_object(pm_path);
        assert_true(objectp(pmob), sprintf("盤木縣房間必須載入成功: %s", pm_path));
        if (pmob) {
            assert_equal("panmu", pmob->query_county(), sprintf("盤木縣房間必須綁定 county_id == panmu: %s", pm_path));
            assert_true(sizeof(pmob->query_exits()) >= 1, sprintf("盤木縣房間必須具備有效出口: %s", pm_path));
        }
    }

    string *zhongshi_rooms = ({
        "/d/counties/zhongshi/southwest_gate.c",
        "/d/counties/zhongshi/market.c",
        "/d/counties/zhongshi/yamen.c",
        "/d/counties/zhongshi/pawnshop.c",
        "/d/counties/zhongshi/post_inn.c",
        "/d/counties/zhongshi/stone_guild.c",
        "/d/counties/zhongshi/crusher_hall.c",
        "/d/counties/zhongshi/leyline_pavilion.c",
        "/d/counties/zhongshi/north_gate.c",
        "/d/counties/zhongshi/shinian_slope.c",
        "/d/counties/zhongshi/watermill_forge.c",
        "/d/counties/zhongshi/chuanshan_camp.c",
        "/d/counties/zhongshi/quarry_winch3.c",
        "/d/counties/zhongshi/terrace_trench.c"
    });
    assert_equal(14, sizeof(zhongshi_rooms), "重石縣必須包含完整 14 間實體房間");
    foreach (string zs_path in zhongshi_rooms) {
        object zsob = load_object(zs_path);
        assert_true(objectp(zsob), sprintf("重石縣房間必須載入成功: %s", zs_path));
        if (zsob) {
            assert_equal("zhongshi", zsob->query_county(), sprintf("重石縣房間必須綁定 county_id == zhongshi: %s", zs_path));
            assert_true(sizeof(zsob->query_exits()) >= 1, sprintf("重石縣房間必須具備有效出口: %s", zs_path));
        }
    }

    // 驗證盤木縣與重石縣 6 處地方考場房間與 SKILL_D 註冊表完全一致
    string *batch1_counties = ({ "panmu", "zhongshi" });
    foreach (string bc in batch1_counties) {
        foreach (string bp in all_paths) {
            mapping beq = sk_d->check_county_qualification_equivalence(bc, bp);
            object exam_room = load_object(beq["room"]);
            assert_true(objectp(exam_room), sprintf("地方考場房間必須存在且可載入: %s", beq["room"]));
            if (exam_room) {
                assert_equal(bp, exam_room->query_qual_path(), sprintf("考場房間道途標記必須匹配: %s", beq["room"]));
                assert_equal(beq["org_id"], exam_room->query_branch_org(), sprintf("考場房間所屬組織必須匹配: %s", beq["room"]));
            }
        }
    }

    // 驗證 MAP_D 盤木縣與重石縣分區地圖渲染
    object map_d = load_object("/secure/map_d");
    assert_true(objectp(map_d), "MAP_D 必須載入成功");
    if (map_d) {
        string pm_map = map_d->draw_panmu_map(0);
        string zs_map = map_d->draw_zhongshi_map(0);
        assert_true(strsrch(pm_map, "盤木縣") != -1, "MAP_D 必須可渲染盤木縣分區地圖");
        assert_true(strsrch(zs_map, "重石縣") != -1, "MAP_D 必須可渲染重石縣分區地圖");
    }
}
