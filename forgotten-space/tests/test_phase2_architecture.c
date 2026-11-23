// /tests/test_phase2_architecture.c
// Phase 2: 標準資料模型與引擎架構驗證 (Region / Route / Lazy Evaluation / Dual-Track)
// 驗證項目：
// 1. region.h 巨集與常數規格完整性 (Spatial, Tier 0~4, Discovery/Access/Survival 三階段)
// 2. ROUTE_D 靜態載入與雙軌延遲查詢 (實體物流 vs 消息情報分離，情報前導延遲小於物流延遲)
// 3. ROUTE_D 道路通阻與離散狀態轉移
// 4. REGION_D 靜態區域載入與標準 JSON 結構
// 5. REGION_D 惰性求值 (Lazy Evaluation) 時間戳差額補償
// 6. REGION_D 指數阻尼回歸演算法 (價格偏離 100% 隨時間阻尼平滑趨向基準，鉗制在 50%~300%)
// 7. REGION_D 離散物理狀態轉移模型 (災情不隨時間自癒，需具體行動方可解除)
// 8. WORLD_STATE_D 宏觀協調中樞與 REGION_D / ROUTE_D 串接
// 9. 太古九城文明依存網絡 (nine_cities_graph.json) 9 個核心節點與 26 條正典依存邊完整性
// 10. 九城城市基本定義 (world/cities/*.json) 結構化載入

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/region.h"

void run_tests(object me) {
    start_test("Phase 2: 標準資料模型與引擎架構 (Daemon/Route/Zone/LazyEval)");

    // ── 1. 驗證 region.h 常數與巨集 ──────────────────────────────
    assert_equal("region", SPATIAL_REGION, "SPATIAL_REGION 定義應為 region");
    assert_equal("zone", SPATIAL_ZONE, "SPATIAL_ZONE 定義應為 zone");
    assert_equal("site", SPATIAL_SITE, "SPATIAL_SITE 定義應為 site");

    assert_equal(0, TIER_0, "TIER_0 應為 0");
    assert_equal(1, TIER_1, "TIER_1 應為 1");
    assert_equal(2, TIER_2, "TIER_2 應為 2");
    assert_equal(3, TIER_3, "TIER_3 應為 3");
    assert_equal(4, TIER_4, "TIER_4 應為 4");

    assert_equal("discovery", EXPLORE_DISCOVERY, "EXPLORE_DISCOVERY 定義應為 discovery");
    assert_equal("access", EXPLORE_ACCESS, "EXPLORE_ACCESS 定義應為 access");
    assert_equal("survival", EXPLORE_SURVIVAL, "EXPLORE_SURVIVAL 定義應為 survival");

    assert_equal(50, PRICE_INDEX_MIN, "PRICE_INDEX_MIN 應為 50");
    assert_equal(100, PRICE_INDEX_BASE, "PRICE_INDEX_BASE 應為 100");
    assert_equal(300, PRICE_INDEX_MAX, "PRICE_INDEX_MAX 應為 300");

    // ── 2. 驗證 ROUTE_D 守護進程與雙軌模型 ────────────────────────
    object route_d = load_object(ROUTE_D);
    assert_true(objectp(route_d), "ROUTE_D 必須成功載入");

    route_d->reset_routes();
    mapping r_zs = route_d->query_route("zhongshi_to_jinshi");
    assert_true(mapp(r_zs), "zhongshi_to_jinshi 路線設定必須存在");
    assert_equal("zhongshi", r_zs["from"], "起點應為 zhongshi");
    assert_equal("jinshi", r_zs["to"], "終點應為 jinshi");

    // 雙軌異步性驗證：消息傳播（60分）必須快於實體貨物運輸（180分）
    int info_delay = route_d->query_information_delay("zhongshi_to_jinshi");
    int freight_delay = route_d->query_freight_delay("zhongshi_to_jinshi");
    int travel_time = route_d->query_travel_time("zhongshi_to_jinshi", "walking");

    assert_equal(60, info_delay, "情報前導延遲應為 60 分鐘");
    assert_equal(180, freight_delay, "大宗貨物衝擊延遲應為 180 分鐘");
    assert_true(info_delay < freight_delay, "雙軌模型：情報傳播速度必須快於大宗貨物抵達");
    assert_equal(180, travel_time, "步行常規交通時間應為 180 分鐘");

    // 出行模式調製驗證
    int horse_time = route_d->query_travel_time("zhongshi_to_jinshi", "horse");
    assert_equal(108, horse_time, "坐騎行旅耗時應快 40% (180 * 0.6 = 108)");

    // 道路通阻與離散狀態轉移
    assert_equal(0, route_d->is_route_blocked("zhongshi_to_jinshi"), "初始道路應為暢通");
    route_d->set_route_blocked("zhongshi_to_jinshi", 1, "山洪坍方，大車難通");
    assert_equal(1, route_d->is_route_blocked("zhongshi_to_jinshi"), "設定封閉後應為受阻");
    assert_equal(-1, route_d->query_travel_time("zhongshi_to_jinshi", "walking"), "受阻道路行旅耗時應回傳 -1");
    assert_equal("山洪坍方，大車難通", route_d->query_route_block_reason("zhongshi_to_jinshi"), "應回傳正確封閉原因");

    // 搶通恢復
    route_d->set_route_blocked("zhongshi_to_jinshi", 0, "搶修完畢");
    assert_equal(0, route_d->is_route_blocked("zhongshi_to_jinshi"), "搶通後應恢復通行");
    assert_equal(180, route_d->query_travel_time("zhongshi_to_jinshi", "walking"), "搶通後交通耗時應恢復正常");

    // ── 3. 驗證 REGION_D 守護進程與靜態設定載入 ─────────────────────
    object reg_d = load_object(REGION_D);
    assert_true(objectp(reg_d), "REGION_D 必須成功載入");

    reg_d->reset_regions();
    mapping all_regs = reg_d->query_all_regions();
    assert_true(mapp(all_regs) && sizeof(all_regs) >= 8, "至少應載入 8 個標準區域定義");
    assert_true(mapp(all_regs["jinshi"]), "金石府城定義應載入");
    assert_true(mapp(all_regs["zhongshi"]), "重石縣定義應載入");
    assert_true(mapp(all_regs["heishipu"]), "黑石鋪定義應載入");

    // 檢查資源與儲量
    int iron_reserve = reg_d->query_region_reserves("zhongshi", "iron_ore");
    assert_equal(12000, iron_reserve, "重石縣初始生鐵儲量應為 12000");

    // 調整儲量
    reg_d->adjust_region_reserves("zhongshi", "iron_ore", -2000);
    assert_equal(10000, reg_d->query_region_reserves("zhongshi", "iron_ore"), "消耗後儲量應為 10000");

    // ── 4. 驗證 Lazy Evaluation 與指數阻尼自然回歸 ─────────────────
    // 初始基準牌價應為 100
    assert_equal(100, reg_d->query_region_price_index("zhongshi"), "初始物價指數應為基準 100%");

    // 人為震盪：價格飆升至 180% (溢價 80%)
    reg_d->adjust_region_price("zhongshi", 80);
    assert_equal(180, reg_d->query_region_price_index("zhongshi"), "價格調整後應為 180%");

    // 模擬時間推進 300 遊戲分鐘 (5 小時)：Lazy Evaluation 結算指數阻尼
    mapping s_damped = reg_d->evaluate_region("zhongshi", reg_d->get_current_gtime() + 300);
    int p_damped = s_damped["price_index"];
    assert_true(p_damped < 180, "經過時間後物價指數必須衰減");
    assert_true(p_damped > 100, "尚未完全回歸時物價指數仍應高於基準 100");
    assert_true(p_damped >= 140 && p_damped <= 160, "300 分鐘後物價指數應阻尼在 140%~160% 區間 (實際: " + p_damped + "%)");

    // 模擬時間推進 2000 遊戲分鐘：平滑完全回歸基準 100%
    mapping s_final = reg_d->evaluate_region("zhongshi", reg_d->get_current_gtime() + 2000);
    assert_equal(100, s_final["price_index"], "經過充裕時間後價格應完全回歸 100% 基準");

    // 價格邊界鉗制 (50% ~ 300%)
    reg_d->adjust_region_price("zhongshi", 300);
    assert_equal(300, reg_d->query_region_price_index("zhongshi"), "上限應嚴格鉗制在 300%");
    reg_d->adjust_region_price("zhongshi", -500);
    assert_equal(50, reg_d->query_region_price_index("zhongshi"), "下限應嚴格鉗制在 50%");
    reg_d->evaluate_region("zhongshi", reg_d->get_current_gtime() + 3000); // 歸回 100%

    // ── 5. 驗證離散物理狀態轉移模型 (災情不自動自癒) ──────────────────
    reg_d->set_region_crisis("zhongshi", "quarry_collapse", 1, ([
        "desc": "重石深井岩層斷裂塌方", "impact_pct": 30
    ]));
    assert_true(mapp(reg_d->query_region_crisis("zhongshi", "quarry_collapse")), "礦難危機應已登記生效");

    // 時間推進 5000 遊戲分鐘，離散災情絕對不得自癒消失
    reg_d->evaluate_region("zhongshi", reg_d->get_current_gtime() + 5000);
    assert_true(mapp(reg_d->query_region_crisis("zhongshi", "quarry_collapse")), "離散狀態轉移：未經具體搶修行動前，坍方危機絕對不得隨時間自癒");

    // 實體工程或行動干預：修復危機
    int res_ok = reg_d->resolve_region_crisis("zhongshi", "quarry_collapse", "repair_quarry");
    assert_equal(1, res_ok, "解決危機操作應回傳成功");
    assert_true(!mapp(reg_d->query_region_crisis("zhongshi", "quarry_collapse")), "解決後危機狀態應已被移除");

    // ── 6. 驗證 WORLD_STATE_D 宏觀協調與分工 ─────────────────────────
    object ws = load_object(WORLD_STATE_D);
    assert_true(objectp(ws), "WORLD_STATE_D 必須成功載入");

    assert_true(objectp(ws->query_region_d()), "WORLD_STATE_D 應可存取 REGION_D");
    assert_true(objectp(ws->query_route_d()), "WORLD_STATE_D 應可存取 ROUTE_D");

    mapping m_timing = ws->query_macro_route_timing("heishipu_to_jinshi", "walking");
    assert_true(mapp(m_timing), "query_macro_route_timing 應回傳有效結構");
    assert_equal(120, m_timing["travel_time"], "黑石關驛道步行時間應為 120 分鐘");
    assert_equal(45, m_timing["info_delay"], "黑石關驛道情報延遲應為 45 分鐘");

    // ── 7. 驗證太古九城文明依存圖與城市結構 ────────────────────────
    string graph_str = read_file(WORLD_DEPENDENCIES_DIR + "nine_cities_graph.json");
    assert_true(graph_str && graph_str != "", "nine_cities_graph.json 必須存在且非空");

    mixed graph_data = json_decode(graph_str);
    assert_true(mapp(graph_data), "nine_cities_graph.json 應能成功解碼為 mapping");
    assert_equal(9, sizeof(graph_data["nodes"]), "太古九城依存圖必須剛好有 9 個核心節點");
    assert_true(sizeof(graph_data["edges"]) >= 26, "太古九城依存圖應包含至少 26 條正典依存邊");

    // 驗證 9 座城市靜態 JSON 定義檔全數存在
    string *expected_cities = ({
        "tianshu", "xuanzhu", "qingming", "guanxing", "cangjing",
        "canglan", "baigong", "zhenyue", "guixu"
    });

    foreach (string c_id in expected_cities) {
        string c_path = WORLD_CITIES_DIR + c_id + ".json";
        string c_content = read_file(c_path);
        assert_true(c_content && c_content != "", "城市定義 " + c_path + " 必須存在");
        mixed c_def = json_decode(c_content);
        assert_true(mapp(c_def), "城市定義 " + c_id + " 應能正常解碼");
        assert_equal(c_id, c_def["id"], "城市 id 必須與檔名匹配");
        assert_true(stringp(c_def["civilization_role"]), "城市 " + c_id + " 必須定義文明機能");
    }

    // ── 8. 驗證巨集拓撲檔 (macro_topology.json) ──────────────────────
    string topo_str = read_file(WORLD_TOPOLOGY_DIR + "macro_topology.json");
    assert_true(topo_str && topo_str != "", "macro_topology.json 必須存在");
    mixed topo_data = json_decode(topo_str);
    assert_true(mapp(topo_data), "macro_topology.json 應能成功解碼");
    assert_true(sizeof(topo_data["connections"]) >= 6, "至少應記錄 6 條已確認之拓撲連線");

    // 驗證完畢，重設守護進程狀態
    route_d->reset_routes();
    reg_d->reset_regions();
}
