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

    // ── 3. 出村進城拓撲連通性檢驗 ──────────────────────────────
    object v_square = load_object("/d/village/square.c");
    assert_true(objectp(v_square), "黑石鋪街市必須載入");
    mapping v_exits = v_square->query_exits();
    assert_equal("/d/city/outer/south_road.c", v_exits["northeast"], "黑石鋪街市東北方出口必須通向南嶺官道 (south_road)");

    object s_road = load_object("/d/city/outer/south_road.c");
    mapping r_exits = s_road->query_exits();
    assert_equal("/d/village/square.c", r_exits["south"], "南嶺官道南方必須通回黑石鋪");
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
}
