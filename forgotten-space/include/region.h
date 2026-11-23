// include/region.h
// 《遺忘的世界》(THE FORGOTTEN SPACE) 宏觀區域、場域、遺跡與雙軌路網資料模型規範 (Phase 2)
// 正典依據：/world/lore/nine_cities_canon.md
// 空間拓撲：/narrative/docs/maps/macro_nine_cities_atlas.md
// 架構手冊：/docs/mudlib_expansion_and_nine_cities_spec.md

#ifndef REGION_H
#define REGION_H

// ── 空間三層巢狀層級 (Spatial Hierarchy) ─────────────────────
// 憲律：Tier 絕非 Region 的單一屬性，而是場域 (Zone / Site) 的屬性。
#define SPATIAL_REGION              "region"       // 宏觀地理/行政/經濟圈 (如金石府城、重石縣、黑石鋪)
#define SPATIAL_ZONE                "zone"         // 具體實體活動場域與生活生態 (如地面都城、城郊採石場、地下暗渠)
#define SPATIAL_SITE                "site"         // Zone 內部特定機關、古代設施、陣基核心 (如天樞南域陣基、南谷殘碑)

// ── 危險挑戰等級 (Danger Tiers 0 ~ 4) ──────────────────────────
#define TIER_0                      0              // 凡俗世外安全區 (安全村落、民宅住宅、避煞集市)
#define TIER_1                      1              // 世俗邊陲與府治 (金石地面都城、大荒六縣、黑石鋪)
#define TIER_2                      2              // 險惡地域與次級宗門 (太古地下暗渠、名山宗門、北荒裂谷)
#define TIER_3                      3              // 史前遺跡與特殊洞天 (天樞南域陣基深殿、桃花源洞天、太古殘殿)
#define TIER_4                      4              // 終極特異點與時空禁區 (歸墟古淵、虛實裂隙特異點)

// ── 三階段探索模型 (Three-Stage Exploration Model) ────────────
// 將「發現」、「開啟權限」與「攻略生存」嚴格解耦
#define EXPLORE_DISCOVERY           "discovery"    // 階段一：認知與發現 (靈性、悟性、天象、古籍、除苔)
#define EXPLORE_ACCESS              "access"       // 階段二：進入與啟動 (實體機關、天門引信物、路引牒文、陣紋排列)
#define EXPLORE_SURVIVAL            "survival"     // 階段三：生存與挑戰 (煞氣抗性、濁氣抵禦、專用辟毒丹藥、防護法器)

// ── 實體交通路網類型 (Physical Route Transport Types) ─────────
#define ROUTE_TYPE_ROAD             "road"         // 鋪裝官道、平原大驛道
#define ROUTE_TYPE_RIVER            "river"        // 漕運河道、平原內河水路
#define ROUTE_TYPE_SEA              "sea"          // 遠洋航線、深水港口海運
#define ROUTE_TYPE_PASS             "pass"         // 險峻關隘、絕嶺山道、峽谷棧道
#define ROUTE_TYPE_FERRY            "ferry"        // 渡口擺渡、深潭舟楫
#define ROUTE_TYPE_SPECIAL          "special"      // 特殊密道、地脈水道、空間傳送

// ── 雙軌傳播模型 (Dual-Track Propagation Types) ───────────────
// 交通網絡與因果傳播分離：道路是重要載體，但非唯一載體
#define PROP_PHYSICAL               "physical"       // 實體物流行旅 (大宗商隊、牛車、大料轉運)
#define PROP_INFORMATION            "information"    // 消息情報傳播 (驛馬、飛鴿傳書、茶棚說書人)
#define PROP_ADMINISTRATIVE         "administrative" // 官府行政政令 (宣道司公文、戒嚴、封關搜捕)
#define PROP_COMMERCIAL             "commercial"     // 市場價格與供需反饋 (盤價波動、黑市抬價)
#define PROP_SPECIAL                "special"        // 陣法通訊、道統心印、地脈煞潮滲透

// ── 數值與物理雙軌自癒模型 (Equilibrium & Healing Models) ────
#define MODEL_EXPONENTIAL_DAMPING   "exponential_damping" // 連續數值自然回歸 (物價、浮動供需)
#define MODEL_STATE_TRANSITION      "state_transition"    // 離散物理狀態轉移 (塌方、破壞需行動修復，不自動自癒)

// ── 市場物價指數限制 (Price Index Bounds) ─────────────────────
#define PRICE_INDEX_MIN             50             // 最低限價 50%
#define PRICE_INDEX_BASE            100            // 基準價格 100%
#define PRICE_INDEX_MAX             300            // 最高限價 300%

// ── 太古文明依存強度與必要性 (Nine Cities Dependency Meta) ────
#define DEP_STRENGTH_S              "S"            // 關鍵依存：斷裂直接造成核心功能失效
#define DEP_STRENGTH_A              "A"            // 強依存：斷裂造成重大效能下降，短期難以替代
#define DEP_STRENGTH_B              "B"            // 中度依存：造成局部缺口，可高成本替代
#define DEP_STRENGTH_C              "C"            // 弱依存：造成不便或效率損失，不影響主功能

#define DEP_NECESSARY               "necessary"    // 文明系統不可缺少
#define DEP_IMPORTANT               "important"    // 對完整能力十分重要
#define DEP_SUPPORTING              "supporting"   // 提供額外支援

// ── 核心守護進程與靜態/動態路徑 (System Daemons & Paths) ──────
#define REGION_D                    "/daemon/region_d.c"
#define ROUTE_D                     "/daemon/route_d.c"

#define WORLD_REGIONS_DIR           "/world/regions/"
#define WORLD_ROUTES_DIR            "/world/routes/"
#define WORLD_CITIES_DIR            "/world/cities/"
#define WORLD_DEPENDENCIES_DIR      "/world/dependencies/"
#define WORLD_TOPOLOGY_DIR          "/world/topology/"

#define DATA_REGIONS_DIR            "/data/regions/"
#define DATA_ROUTES_DIR             "/data/routes/"

#endif // REGION_H
