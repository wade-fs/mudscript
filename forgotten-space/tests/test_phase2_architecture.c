// /tests/test_phase2_architecture.c
// Phase 2: 標準資料模型與引擎架構驗證 (Region / Route / Zone / Site / Lazy Evaluation / Dual-Track)
// 依據：forgotten-space/world/lore/nine_cities_canon.md、world/lore/second_era_ark_canon.md 與 world/specifications/spatial_schema.md (v1.2)
// 驗證項目：
// 1. region.h 巨集與常數規格完整性 (Spatial, Tier 0~4, Discovery/Access/Survival, Route Status, Directionality)
// 2. ROUTE_D 靜態載入與雙軌延遲查詢 (實體物流 vs 消息情報分離，情報前導延遲小於物流延遲)
// 3. ROUTE_D 道路狀態轉移 (OPEN/RESTRICTED/BLOCKED/DESTROYED/SEALED) 與雙向拓撲查找
// 4. 正典保護：拓荒縣 (tuogu) 宏觀拓撲無直通道路
// 5. REGION_D 靜態區域載入與地理空間中繼中立性 (position: null, LOCAL_GAME_SPACE)
// 6. Zone 與 Site 實體化註冊、查詢與全量引用完整性 (region_id / zone_id / room_refs 存在性)
// 7. Danger Tier 解耦驗證：Tier 屬於 Zone/Site，同一 Region 包含多種 Tier
// 8. REGION_D 惰性求值 (Lazy Evaluation) 與離散指數阻尼精確驗證 (D_{n+1} = 0.9 * D_n)
// 9. REGION_D 離散物理狀態轉移模型 (災情不隨時間自癒，需具體行動方可解除)
// 10. REGION_D 動態狀態持久化 round-trip (save_region / restore_region)
// 11. WORLD_STATE_D 宏觀協調中樞與 REGION_D / ROUTE_D 串接
// 12. 太古九城文明依存網絡 (nine_cities_graph.json) 9 節點、32 條正典邊、三條關鍵鏈與雙網分離結構驗證
// 13. 九城城市定義狀態解耦 (ancient_status, remaining_structure_status, modern_manifestation, access_status)
// 14. 宏觀拓撲檔 (macro_topology.json) 19 節點、16 連線、route_ref 雙向一致性與拓荒縣正典保護

inherit "/std/test_case.c";

#include "/include/globals.h"
#include "/include/region.h"

void run_tests(object me) {
    start_test("Phase 2: 標準資料模型與引擎架構 (Daemon/Route/Zone/Site/LazyEval)");

    // ── 1. 驗證 region.h 常數與巨集 ──────────────────────────────
    assert_equal("1.1", SCHEMA_VERSION_1_1, "SCHEMA_VERSION_1_1 定義應為 1.1");

    assert_equal("region", SPATIAL_REGION, "SPATIAL_REGION 定義應為 region");
    assert_equal("zone", SPATIAL_ZONE, "SPATIAL_ZONE 定義應為 zone");
    assert_equal("site", SPATIAL_SITE, "SPATIAL_SITE 定義應為 site");

    assert_equal(0, TIER_0, "TIER_0 應為 0");
    assert_equal(1, TIER_1, "TIER_1 應為 1");
    assert_equal(2, TIER_2, "TIER_2 應為 2");
    assert_equal(3, TIER_3, "TIER_3 應為 3");
    assert_equal(4, TIER_4, "TIER_4 應為 4");

    assert_equal("OPEN", ROUTE_STATUS_OPEN, "ROUTE_STATUS_OPEN 定義應為 OPEN");
    assert_equal("RESTRICTED", ROUTE_STATUS_RESTRICTED, "ROUTE_STATUS_RESTRICTED 定義應為 RESTRICTED");
    assert_equal("BLOCKED", ROUTE_STATUS_BLOCKED, "ROUTE_STATUS_BLOCKED 定義應為 BLOCKED");
    assert_equal("DESTROYED", ROUTE_STATUS_DESTROYED, "ROUTE_STATUS_DESTROYED 定義應為 DESTROYED");
    assert_equal("SEALED", ROUTE_STATUS_SEALED, "ROUTE_STATUS_SEALED 定義應為 SEALED");
    assert_equal("UNKNOWN", ROUTE_STATUS_UNKNOWN, "ROUTE_STATUS_UNKNOWN 定義應為 UNKNOWN");

    assert_equal("BIDIRECTIONAL", ROUTE_DIR_BIDIRECTIONAL, "ROUTE_DIR_BIDIRECTIONAL 應為 BIDIRECTIONAL");
    assert_equal("FORWARD_ONLY", ROUTE_DIR_FORWARD_ONLY, "ROUTE_DIR_FORWARD_ONLY 應為 FORWARD_ONLY");
    assert_equal("BACKWARD_ONLY", ROUTE_DIR_BACKWARD_ONLY, "ROUTE_DIR_BACKWARD_ONLY 應為 BACKWARD_ONLY");

    assert_equal("discovery", EXPLORE_DISCOVERY, "EXPLORE_DISCOVERY 定義應為 discovery");
    assert_equal("access", EXPLORE_ACCESS, "EXPLORE_ACCESS 定義應為 access");
    assert_equal("survival", EXPLORE_SURVIVAL, "EXPLORE_SURVIVAL 定義應為 survival");

    assert_equal(50, PRICE_INDEX_MIN, "PRICE_INDEX_MIN 應為 50");
    assert_equal(100, PRICE_INDEX_BASE, "PRICE_INDEX_BASE 應為 100");
    assert_equal(300, PRICE_INDEX_MAX, "PRICE_INDEX_MAX 應為 300");

    assert_equal("/world/zones/", WORLD_ZONES_DIR, "WORLD_ZONES_DIR 定義正確");
    assert_equal("/world/sites/", WORLD_SITES_DIR, "WORLD_SITES_DIR 定義正確");

    // ── 2. 驗證 ROUTE_D 守護進程與雙軌模型 ────────────────────────
    object route_d = load_object(ROUTE_D);
    assert_true(objectp(route_d), "ROUTE_D 必須成功載入");

    route_d->reset_routes();
    mapping r_zs = route_d->query_route("zhongshi_to_jinshi");
    assert_true(mapp(r_zs), "zhongshi_to_jinshi 路線設定必須存在");
    assert_equal("zhongshi", r_zs["from"], "起點應為 zhongshi");
    assert_equal("jinshi", r_zs["to"], "終點應為 jinshi");
    assert_equal("1.1", r_zs["schema_version"], "路線 schema_version 應為 1.1");
    assert_equal(ROUTE_DIR_BIDIRECTIONAL, route_d->query_directionality("zhongshi_to_jinshi"), "重石至金石應為雙向通路");

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

    // ── 3. 驗證 ROUTE_D 狀態轉移與雙向拓撲查找 ───────────────────────
    assert_equal(ROUTE_STATUS_OPEN, route_d->query_route_status("zhongshi_to_jinshi"), "初始道路狀態應為 OPEN");
    assert_equal(0, route_d->is_route_blocked("zhongshi_to_jinshi"), "初始道路 blocked 應為 0");

    // 狀態轉移：BLOCKED
    route_d->set_route_status("zhongshi_to_jinshi", ROUTE_STATUS_BLOCKED, "山洪坍方，大車難通");
    assert_equal(ROUTE_STATUS_BLOCKED, route_d->query_route_status("zhongshi_to_jinshi"), "設定封閉後應為 BLOCKED");
    assert_equal(1, route_d->is_route_blocked("zhongshi_to_jinshi"), "BLOCKED 狀態下 is_route_blocked 應為 1");
    assert_equal(-1, route_d->query_travel_time("zhongshi_to_jinshi", "walking"), "受阻道路行旅耗時應回傳 -1");
    assert_equal("山洪坍方，大車難通", route_d->query_route_block_reason("zhongshi_to_jinshi"), "應回傳正確封閉原因");

    // 狀態轉移：RESTRICTED (受限通行，但非完全封死)
    route_d->set_route_status("zhongshi_to_jinshi", ROUTE_STATUS_RESTRICTED, "官府盤查");
    assert_equal(ROUTE_STATUS_RESTRICTED, route_d->query_route_status("zhongshi_to_jinshi"), "狀態應為 RESTRICTED");
    assert_equal(0, route_d->is_route_blocked("zhongshi_to_jinshi"), "RESTRICTED 狀態不應完全封鎖 blocked");

    // 搶通恢復：OPEN
    route_d->set_route_status("zhongshi_to_jinshi", ROUTE_STATUS_OPEN, "搶修完畢");
    assert_equal(ROUTE_STATUS_OPEN, route_d->query_route_status("zhongshi_to_jinshi"), "搶通後應恢復 OPEN");
    assert_equal(0, route_d->is_route_blocked("zhongshi_to_jinshi"), "搶通後 blocked 應為 0");
    assert_equal(180, route_d->query_travel_time("zhongshi_to_jinshi", "walking"), "搶通後交通耗時應恢復正常");

    // 拓撲查找與方向相容性
    assert_equal("zhongshi_to_jinshi", route_d->query_route_between("zhongshi", "jinshi"), "正向查找重石至金石路線");
    assert_equal("zhongshi_to_jinshi", route_d->query_route_between("jinshi", "zhongshi"), "雙向通路反向查找金石至重石路線");

    // ── 4. 正典保護：拓荒縣無直通道路 ──────────────────────────
    assert_equal(0, route_d->query_route_between("tuogu", "jinshi"), "正典保護：拓荒縣不得捏造與金石之直通道路");

    // ── 5. 驗證 REGION_D 區域載入與地理空間中立性 ───────────────────
    object reg_d = load_object(REGION_D);
    assert_true(objectp(reg_d), "REGION_D 必須成功載入");

    reg_d->reset_regions();
    mapping all_regs = reg_d->query_all_regions();
    assert_true(mapp(all_regs) && sizeof(all_regs) >= 8, "至少應載入 8 個標準區域定義");

    string *canon_regions = ({ "jinshi", "zhongshi", "heishipu", "qinghe", "liefan", "zhenfeng", "panmu", "tuogu" });
    foreach (string r_id in canon_regions) {
        assert_true(mapp(all_regs[r_id]), "區域 " + r_id + " 定義應已載入");
        mapping r_def = all_regs[r_id];
        assert_equal("1.1", r_def["schema_version"], "區域 " + r_id + " schema_version 應為 1.1");
        assert_true(mapp(r_def["geography"]), "區域 " + r_id + " 必須包含 geography 定義");
        assert_true(r_def["geography"]["position"] == 0, "區域 " + r_id + " position 應為 null (未確認絕對座標)");
        assert_equal("LOCAL_GAME_SPACE", r_def["geography"]["coordinate_space"], "區域 " + r_id + " 座標空間應標記為 LOCAL_GAME_SPACE");
        assert_equal("CONFIRMED", r_def["confidence"], "區域 " + r_id + " 可信度應為 CONFIRMED");
    }

    // 檢查資源與儲量
    int iron_reserve = reg_d->query_region_reserves("zhongshi", "iron_ore");
    assert_equal(12000, iron_reserve, "重石縣初始生鐵儲量應為 12000");

    reg_d->adjust_region_reserves("zhongshi", "iron_ore", -2000);
    assert_equal(10000, reg_d->query_region_reserves("zhongshi", "iron_ore"), "消耗後儲量應為 10000");

    // ── 6. 驗證 Zone 與 Site 正式化註冊與查詢 ───────────────────────
    mapping z_jinshi_ug = reg_d->query_zone("jinshi_underground");
    assert_true(mapp(z_jinshi_ug), "jinshi_underground 場域設定必須存在");
    assert_equal("jinshi", z_jinshi_ug["region_id"], "jinshi_underground 所屬區域應為 jinshi");
    assert_equal("UNDERGROUND", z_jinshi_ug["zone_type"], "場域類型應為 UNDERGROUND");
    assert_equal(2, z_jinshi_ug["danger_tier"], "jinshi_underground 危險等級應為 Tier 2");

    mapping s_ruins = reg_d->query_site("tianshu_south_ruins_hall");
    assert_true(mapp(s_ruins), "tianshu_south_ruins_hall 地點設定必須存在");
    assert_equal("jinshi_underground", s_ruins["zone_id"], "南外圍大廳所屬場域應為 jinshi_underground");
    assert_equal(3, s_ruins["danger_tier"], "南外圍大廳危險等級應為 Tier 3");
    assert_true(pointerp(s_ruins["room_refs"]) && sizeof(s_ruins["room_refs"]) > 0, "南外圍大廳應包含 room_refs 陣列");
    assert_equal("/d/city/under/ruins_hall.c", s_ruins["room_refs"][0], "南外圍大廳 LPC 房間映射路徑正確");

    // 查詢區域所屬之所有 Zones
    string *jinshi_zones = reg_d->query_zones_by_region("jinshi");
    assert_true(member_array("jinshi_surface", jinshi_zones) != -1, "金石府城應包含 jinshi_surface 場域");
    assert_true(member_array("jinshi_underground", jinshi_zones) != -1, "金石府城應包含 jinshi_underground 場域");

    // 查詢場域所屬之所有 Sites
    string *ug_sites = reg_d->query_sites_by_zone("jinshi_underground");
    assert_equal(3, sizeof(ug_sites), "jinshi_underground 應包含 3 個正典 Sites");
    assert_true(member_array("tianshu_south_ruins_hall", ug_sites) != -1, "應包含 tianshu_south_ruins_hall");
    assert_true(member_array("jinshi_black_market", ug_sites) != -1, "應包含 jinshi_black_market");
    assert_true(member_array("jinshi_canal_hub", ug_sites) != -1, "應包含 jinshi_canal_hub");

    // 全量 Zone / Site 參照一致性驗證 (region_id / zone_id / room_refs 實體檔存在)
    mapping all_zones = reg_d->query_all_zones();
    mapping all_sites = reg_d->query_all_sites();
    assert_true(mapp(all_zones) && sizeof(all_zones) >= 23, "至少應載入 23 個正式 Zone JSON 定義");
    assert_true(mapp(all_sites) && sizeof(all_sites) >= 9, "至少應載入 9 個正式 Site JSON 定義");
    foreach (string z_id, mapping z_def in all_zones) {
        assert_true(mapp(all_regs[z_def["region_id"]]), "Zone " + z_id + " 所屬 region_id 必須存在於 REGION_D");
    }
    foreach (string s_id, mapping s_def in all_sites) {
        assert_true(mapp(all_zones[s_def["zone_id"]]), "Site " + s_id + " 所屬 zone_id 必須存在於 REGION_D");
        assert_true(pointerp(s_def["room_refs"]) && sizeof(s_def["room_refs"]) > 0,
                    "Site " + s_id + " 必須宣告非空 room_refs");
        foreach (string rref in s_def["room_refs"]) {
            assert_true(file_size(rref) > 0, "Site " + s_id + " 引用房間必須存在於檔案系統: " + rref);
        }
    }

    // ── 7. 驗證 Danger Tier 解耦 ─────────────────────────────────
    // 在同一個金石府城 (jinshi) 區域內：
    // 地表場域 (jinshi_surface) 為 Tier 1
    // 地下場域 (jinshi_underground) 為 Tier 2
    // 古陣大廳地點 (tianshu_south_ruins_hall) 為 Tier 3
    // 證明 Tier 完全解耦自 Region，屬於 Zone/Site
    mapping z_surface = reg_d->query_zone("jinshi_surface");
    assert_equal(1, z_surface["danger_tier"], "地表城區為 Tier 1");
    assert_equal(2, z_jinshi_ug["danger_tier"], "地下暗渠為 Tier 2");
    assert_equal(3, s_ruins["danger_tier"], "古代殘廳為 Tier 3");

    // ── 8. 驗證 Lazy Evaluation 與離散指數阻尼 (D_{n+1} = 0.9 * D_n) ───
    assert_equal(100, reg_d->query_region_price_index("zhongshi"), "初始物價指數應為基準 100%");

    // 人為震盪：價格提高至 200% (偏離基準 100)
    reg_d->adjust_region_price("zhongshi", 100);
    assert_equal(200, reg_d->query_region_price_index("zhongshi"), "調整後價格應為 200%");

    // 推進 60 遊戲分鐘 (1 週期)：D_1 = 100 * 0.9 = 90，物價應為 190
    mapping s_step1 = reg_d->evaluate_region("zhongshi", reg_d->get_current_gtime() + 60);
    assert_equal(190, s_step1["price_index"], "步進 1 (60分) 指數阻尼回歸應為 190%");

    // 再推進 60 遊戲分鐘 (共 120 分鐘)：D_2 = 90 * 0.9 = 81，物價應為 181
    mapping s_step2 = reg_d->evaluate_region("zhongshi", reg_d->get_current_gtime() + 120);
    assert_equal(181, s_step2["price_index"], "步進 2 (120分) 指數阻尼回歸應為 181%");

    // 推進 3000 遊戲分鐘：平滑完全回歸基準 100%
    mapping s_final = reg_d->evaluate_region("zhongshi", reg_d->get_current_gtime() + 3000);
    assert_equal(100, s_final["price_index"], "經過充裕時間後價格應完全回歸 100% 基準");

    // 價格邊界鉗制 (50% ~ 300%)
    reg_d->adjust_region_price("zhongshi", 300);
    assert_equal(300, reg_d->query_region_price_index("zhongshi"), "上限應嚴格鉗制在 300%");
    reg_d->adjust_region_price("zhongshi", -500);
    assert_equal(50, reg_d->query_region_price_index("zhongshi"), "下限應嚴格鉗制在 50%");
    reg_d->evaluate_region("zhongshi", reg_d->get_current_gtime() + 3000); // 歸回 100%

    // ── 9. 驗證離散物理狀態轉移模型 (災情不自動自癒) ──────────────────
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

    // ── 10. 驗證動態持久化 Round-trip (save_region / restore_region) ──
    reg_d->adjust_region_price("zhongshi", 25);
    assert_equal(125, reg_d->query_region_price_index("zhongshi"), "調整價格為 125%");
    int save_ok = reg_d->save_region("zhongshi");
    assert_equal(1, save_ok, "save_region 應回傳成功");

    // 模擬記憶體重設
    reg_d->reset_regions();
    assert_equal(100, reg_d->query_region_price_index("zhongshi"), "reset 後記憶體狀態恢復預設 100%");

    // 從磁碟恢復持久化狀態
    int restore_ok = reg_d->restore_region("zhongshi");
    assert_equal(1, restore_ok, "restore_region 應回傳成功");
    assert_equal(125, reg_d->query_region_price_index("zhongshi"), "持久化狀態成功恢復為 125%");

    // 清理測試寫入之存檔
    reg_d->remove_save_file("zhongshi");
    reg_d->reset_regions();

    // ── 11. 驗證 WORLD_STATE_D 宏觀協調中樞 ────────────────────────
    object ws = load_object(WORLD_STATE_D);
    assert_true(objectp(ws), "WORLD_STATE_D 必須成功載入");

    assert_true(objectp(ws->query_region_d()), "WORLD_STATE_D 應可存取 REGION_D");
    assert_true(objectp(ws->query_route_d()), "WORLD_STATE_D 應可存取 ROUTE_D");

    mapping m_timing = ws->query_macro_route_timing("heishipu_to_jinshi", "walking");
    assert_true(mapp(m_timing), "query_macro_route_timing 應回傳有效結構");
    assert_equal(120, m_timing["travel_time"], "黑石關驛道步行時間應為 120 分鐘");
    assert_equal(45, m_timing["info_delay"], "黑石關驛道情報延遲應為 45 分鐘");

    // ── 12. 驗證太古九城文明依存圖結構、正典語義與雙網分離 ──────────────
    string graph_str = read_file(WORLD_DEPENDENCIES_DIR + "nine_cities_graph.json");
    assert_true(graph_str && graph_str != "", "nine_cities_graph.json 必須存在且非空");

    mixed graph_data = json_decode(graph_str);
    assert_true(mapp(graph_data), "nine_cities_graph.json 應能成功解碼為 mapping");
    assert_equal(9, sizeof(graph_data["nodes"]), "太古九城依存圖必須剛好有 9 個核心節點");
    assert_equal(32, sizeof(graph_data["edges"]), "太古九城依存圖應精確對齊 nine_cities_canon.md §4.2 之 32 條正典依存邊");

    string *expected_cities = ({
        "tianshu", "xuanzhu", "qingming", "guanxing", "cangjing",
        "canglan", "baigong", "zhenyue", "guixu"
    });
    mapping graph_node_ids = ([]);
    foreach (mapping gnode in graph_data["nodes"]) {
        assert_true(stringp(gnode["id"]) && member_array(gnode["id"], expected_cities) != -1,
                    "依存圖節點必須為正典九城 ID");
        assert_true(!graph_node_ids[gnode["id"]], "依存圖節點 ID 不得重複: " + gnode["id"]);
        graph_node_ids[gnode["id"]] = 1;
    }
    assert_equal(9, sizeof(graph_node_ids), "9 個太古正典城市節點必須全數出現且無重複");

    string *valid_strengths = ({ "S", "A", "B", "C" });
    string *valid_necessities = ({ "NECESSARY", "IMPORTANT", "SUPPORTING" });
    string *valid_confidences = ({ "CONFIRMED", "INFERRED", "RUMORED", "UNKNOWN", "DISPUTED" });
    mapping seen_edges = ([]);
    int tianshu_coord_count = 0;

    // 驗證 Edge 結構、枚舉值、無自環與無重複邊
    foreach (mapping edge in graph_data["edges"]) {
        string src = edge["source"];
        string dst = edge["target"];
        assert_true(stringp(src) && graph_node_ids[src], "Edge source 必須為合法九城節點");
        assert_true(stringp(dst) && graph_node_ids[dst], "Edge target 必須為合法九城節點");
        assert_true(src != dst, "依存邊不得構成自環: " + src);

        string pair_key = src + "->" + dst;
        assert_true(!seen_edges[pair_key], "依存圖不得存在重複方向邊: " + pair_key);
        seen_edges[pair_key] = edge;

        assert_true(stringp(edge["dependency_type"]) && edge["dependency_type"] != "", "Edge dependency_type 必須存在");
        assert_true(stringp(edge["relation"]) && edge["relation"] != "", "Edge relation 必須存在");
        assert_true(member_array(edge["strength"], valid_strengths) != -1,
                    "Edge strength 必須屬於 S/A/B/C: " + pair_key);
        assert_true(member_array(edge["necessity"], valid_necessities) != -1,
                    "Edge necessity 必須屬於 NECESSARY/IMPORTANT/SUPPORTING: " + pair_key);
        assert_true(member_array(edge["confidence"], valid_confidences) != -1,
                    "Edge confidence 必須屬於正典五級標記: " + pair_key);
        assert_true(pointerp(edge["evidence"]) && sizeof(edge["evidence"]) > 0 && stringp(edge["evidence"][0]),
                    "Edge evidence 必須包含至少一筆正典依據: " + pair_key);

        if (src == "tianshu" && edge["dependency_type"] == "COORDINATION" && edge["relation"] == "COORDINATES") {
            tianshu_coord_count++;
        }
    }
    assert_equal(8, tianshu_coord_count, "天樞城必須對其餘八城建立完整 8 條 COORDINATION / COORDINATES 依存邊");

    // 驗證 nine_cities_canon.md §4.4 三條關鍵依存鏈（防禦存續／材料工程／知識決策）
    string *critical_chain_edges = ({
        "guanxing->tianshu", "tianshu->zhenyue", "zhenyue->guixu",
        "guanxing->zhenyue", "zhenyue->tianshu", "guixu->tianshu",
        "xuanzhu->baigong", "canglan->xuanzhu", "qingming->xuanzhu",
        "guanxing->cangjing", "cangjing->guanxing",
        "cangjing->tianshu", "cangjing->baigong", "cangjing->qingming"
    });
    foreach (string ck in critical_chain_edges) {
        assert_true(mapp(seen_edges[ck]), "正典三條關鍵依存鏈必須包含邊: " + ck);
    }

    // 雙網分離保護 (spatial_schema.md §11.5)：文明依存邊不得自動轉成 ROUTE_D 實體道路
    mapping all_routes = route_d->query_all_routes();
    assert_equal(6, sizeof(all_routes), "現代已確認實體 Route 維持 6 條（不捏造九城或拓荒縣道路）");
    foreach (string r_id, mapping r_item in all_routes) {
        assert_true(!graph_node_ids[r_item["from"]] && !graph_node_ids[r_item["to"]],
                    "雙網分離：實體 Route " + r_id + " 不得以太古九城作為現代交通端點");
    }

    // ── 13. 驗證太古九城城市定義狀態解耦 (Section 10.3) ───────────────
    foreach (string c_id in expected_cities) {
        string c_path = WORLD_CITIES_DIR + c_id + ".json";
        string c_content = read_file(c_path);
        assert_true(c_content && c_content != "", "城市定義 " + c_path + " 必須存在");
        mixed c_def = json_decode(c_content);
        assert_true(mapp(c_def), "城市定義 " + c_id + " 應能正常解碼");
        assert_equal(c_id, c_def["id"], "城市 id 必須與檔名匹配");
        assert_equal("1.1", c_def["schema_version"], "城市 " + c_id + " schema_version 應為 1.1");
        assert_equal("RUINED", c_def["ancient_status"], "太古文明狀態應標記為 RUINED");
        assert_true(stringp(c_def["remaining_structure_status"]), "殘留構造狀態必須定義");
        assert_true(stringp(c_def["modern_manifestation"]), "現代顯化形式必須定義");
        assert_true(stringp(c_def["access_status"]), "存取/探勘狀態必須定義");
        assert_true(stringp(c_def["status"]), "既有 status 欄位必須保留以相容舊程式");
        assert_true(stringp(c_def["civilization_role"]), "城市 " + c_id + " 必須定義文明機能");
    }

    // ── 14. 驗證宏觀拓撲檔 (macro_topology.json) 結構與正典保護 ─────────
    string topo_str = read_file(WORLD_TOPOLOGY_DIR + "macro_topology.json");
    assert_true(topo_str && topo_str != "", "macro_topology.json 必須存在");
    mixed topo_data = json_decode(topo_str);
    assert_true(mapp(topo_data), "macro_topology.json 應能成功解碼");
    assert_equal(19, sizeof(topo_data["nodes"]), "宏觀拓撲應記錄全部 19 個現代／三～四卷 Region 節點");
    assert_equal(16, sizeof(topo_data["connections"]), "宏觀拓撲應記錄 16 條已確認連線（6 實體路網 + 10 三～四卷跨區連線）");

    mapping topo_node_ids = ([]);
    foreach (mapping tnode in topo_data["nodes"]) {
        string nid = tnode["id"];
        assert_true(stringp(nid) && !topo_node_ids[nid], "拓撲節點 ID 必須有效且不重複: " + nid);
        assert_true(mapp(all_regs[nid]), "拓撲節點必須對應已載入之 REGION_D 區域: " + nid);
        assert_true(!graph_node_ids[nid], "雙網分離：太古九城節點不得混充現代宏觀拓撲節點: " + nid);
        topo_node_ids[nid] = 1;
    }

    int route_ref_count = 0;
    int tuogu_conn_count = 0;
    foreach (mapping conn in topo_data["connections"]) {
        string c_from = conn["from"];
        string c_to = conn["to"];
        assert_true(topo_node_ids[c_from] && topo_node_ids[c_to], "拓撲連線端點必須皆存在於 nodes");
        assert_true(c_from != c_to, "拓撲連線不得構成自環: " + c_from);
        assert_true(member_array(conn["confidence"], valid_confidences) != -1,
                    "拓撲連線 confidence 必須為正典五級標記");
        if (c_from == "tuogu" || c_to == "tuogu") tuogu_conn_count++;
        if (stringp(conn["route_ref"]) && conn["route_ref"] != "") {
            route_ref_count++;
            mapping r_match = route_d->query_route(conn["route_ref"]);
            assert_true(mapp(r_match), "拓撲 route_ref 必須存在於 ROUTE_D: " + conn["route_ref"]);
            assert_true((r_match["from"] == c_from && r_match["to"] == c_to) ||
                        (r_match["from"] == c_to && r_match["to"] == c_from),
                        "拓撲 route_ref 端點必須與 ROUTE_D 定義一致: " + conn["route_ref"]);
        }
    }
    assert_equal(6, route_ref_count, "宏觀拓撲應有 6 條連線對應至 ROUTE_D 實體路線");
    assert_equal(0, tuogu_conn_count, "正典保護：拓荒縣 (tuogu) 於宏觀拓撲維持無已確認直通連線");

    // 驗證完畢，重設守護進程狀態
    route_d->reset_routes();
    reg_d->reset_regions();
}
