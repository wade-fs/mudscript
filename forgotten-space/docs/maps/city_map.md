# 金石都城九大分區詳細拓撲圖 (City Map)

金石府城為 Tier 1 區域網絡的政治、商貿、工匠與武衛中心。全城被護城河與高聳城牆環繞，由外城四關門戶進出，內部分為九大核心分區。

---

## 💻 遊戲內指令輸出 (`map city`)

當玩家在遊戲內輸入 `map city` 或身處都城區輸入 `map` 時，顯示如下 ASCII 空間地圖：

```text
【金石都城九大分區空間地圖】
──────────────────────────────────────────────────────────
                        [外城大車馬店]
                              │
      [亂葬義塚] ─── 【金石北關】 ── (北城望荒箭樓)
                             │
  [官道大貨棧] ─── [北關前校場] ─── [關外車馬店]
                             │
    [匠籍登記處] ─── 【百工總會】 ─── (分業工坊街：鍛/木/石/革/藥/硝)
                             │
  【宣道司】 ────── 【中央青石廣場】 ────── 【鎮武軍鎮】 ─── 【東關城門】
   (玄機真人)          (士民商貿)          (霸山總教頭)      (烈礬/濁水)
   (摘星台/偏殿)       ┌─────┴─────┐          (大校場/生死擂)
   (聽經閣)        [府衙正堂]   [通寶錢莊]     (披甲兵器庫)
                       │           │
                   [學塾/醫館]  [通寶當鋪] ── [鬼市暗巷] (下通城下暗渠)
                       └─────┬─────┘
                             │
                        [六縣專材長街] ─── [金石商會總堂]
                             │                 │
                        [大料初堆棧] ─── [遠行車馬大院]
                             │
  【西水門】 ────── 【金石南關】 ─── [南關車馬小棧]
 (青河水路漕運)              │
                             │ (南嶺官道)
                             ▼
                     往 【黑石鋪】 聚落
──────────────────────────────────────────────────────────
```

---

## 🗺️ 九大分區結構化 Mermaid 拓撲子圖

```mermaid
flowchart TD
    %% ─────────────────────────────────────────────────────────────
    %% 1. 北門與外城貨運分區
    %% ─────────────────────────────────────────────────────────────
    subgraph NorthGateSub["【金石北關與外城樞紐】"]
        GATE_N["金石北關 (gate_north)"]
        GATE_N_PLAZA["北關前校場 (gate_plaza)"]
        GATE_N_DEPOT["外城大車馬店 (post_depot)"]
        GATE_N_WAREHOUSE["官道大貨棧 (gate_warehouse)"]
        GATE_N_INN["關外車馬店 (gate_inn)"]
        GRAVEYARD["亂葬義塚 (graveyard)"]
        TOWER_N["北城望荒箭樓 (wall_tower_n)"]

        GATE_N_DEPOT --- GATE_N
        GRAVEYARD --- GATE_N
        GATE_N --- TOWER_N
        GATE_N --- GATE_N_PLAZA
        GATE_N_WAREHOUSE --- GATE_N_PLAZA --- GATE_N_INN
    end

    %% ─────────────────────────────────────────────────────────────
    %% 2. 百工總會工坊分區 (物道)
    %% ─────────────────────────────────────────────────────────────
    subgraph GongSub["【百工總會工坊分區 (物道統)】"]
        GONG_GATE["百工總會大門 (gong_gate)"]
        GONG_REG["匠籍登記處 (gong_registry)"]
        GONG_HALL["天工殿堂 (gong_hall)"]
        GONG_FORGE["鍛鐵金石坊 (gong_forge)"]
        GONG_WOOD["機巧木作坊 (gong_wood)"]
        GONG_STONE["精研石雕坊 (gong_stone)"]
        GONG_LEATHER["百鞣皮甲坊 (gong_leather)"]
        GONG_ALCH["丹丸物性坊 (gong_alchemy)"]
        GONG_FIRE["烈性火硝坊 (gong_fireworks)"]

        GONG_GATE --- GONG_REG
        GONG_GATE --- GONG_HALL
        GONG_HALL --- GONG_FORGE
        GONG_HALL --- GONG_WOOD
        GONG_HALL --- GONG_STONE
        GONG_HALL --- GONG_LEATHER
        GONG_HALL --- GONG_ALCH
        GONG_HALL --- GONG_FIRE
    end

    %% ─────────────────────────────────────────────────────────────
    %% 3. 宣道司道統分區 (法道)
    %% ─────────────────────────────────────────────────────────────
    subgraph DaoSub["【宣道司分區 (法道統)】"]
        DAO_GATE["宣道司山門 (dao_gate)"]
        DAO_HALL["太虛三清殿 (dao_hall)"]
        DAO_OBS["摘星台 (dao_observatory)"]
        DAO_ROOF["聽經閣 (dao_roof)"]
        DAO_QUIET["清修靜室 (dao_quiet)"]

        DAO_GATE --- DAO_HALL
        DAO_HALL --- DAO_OBS
        DAO_HALL --- DAO_ROOF
        DAO_HALL --- DAO_QUIET
    end

    %% ─────────────────────────────────────────────────────────────
    %% 4. 中央市井與府衙核心
    %% ─────────────────────────────────────────────────────────────
    subgraph CenterSub["【中央市井與政務核心】"]
        SQUARE["中央青石廣場 (square)"]
        YAMEN["府衙正堂 (yamen)"]
        YAMEN_ARCH["案牘庫 (yamen_archive)"]
        YAMEN_PRIS["府衙大牢 (yamen_prison)"]
        GRANARY["官平糧倉 (granary)"]
        ACADEMY["流泉學塾 (academy)"]
        CLINIC["百草堂醫館 (clinic)"]
        BANK["通寶錢莊 (bank)"]
        PAWNSHOP["聚珍當鋪 (pawnshop)"]
        BLACK_ALLEY["鬼市暗巷 (black_alley)"]
        INN_MAIN["金石大客棧 (inn_main)"]
        POST_STATION["官辦驛傳總所 (post_station)"]

        SQUARE --- YAMEN
        YAMEN --- YAMEN_ARCH
        YAMEN --- YAMEN_PRIS
        SQUARE --- ACADEMY
        ACADEMY --- CLINIC
        SQUARE --- BANK
        BANK --- PAWNSHOP
        PAWNSHOP --- BLACK_ALLEY
        SQUARE --- INN_MAIN
        INN_MAIN --- GRANARY
        SQUARE --- POST_STATION
    end

    %% ─────────────────────────────────────────────────────────────
    %% 5. 鎮武軍鎮衛所分區 (力道)
    %% ─────────────────────────────────────────────────────────────
    subgraph WuSub["【鎮武軍鎮衛所 (力道統)】"]
        WU_GATE["軍鎮大閘門 (wu_gate)"]
        WU_PLAZA["演武大校場 (wu_plaza)"]
        WU_ARENA["黑鐵生死擂 (wu_arena)"]
        WU_HALL["偏將軍帳 (wu_hall)"]
        WU_ARMORY["披甲兵器庫 (wu_armory)"]
        WU_BARRACKS["鎮武兵營 (wu_barracks)"]

        WU_GATE --- WU_PLAZA
        WU_PLAZA --- WU_ARENA
        WU_PLAZA --- WU_HALL
        WU_HALL --- WU_ARMORY
        WU_HALL --- WU_BARRACKS
    end

    %% ─────────────────────────────────────────────────────────────
    %% 6. 南部商貿與六縣大料棧
    %% ─────────────────────────────────────────────────────────────
    subgraph SouthSub["【南部商貿與大料分區】"]
        MARKET_SPEC["六縣專材長街 (market_special)"]
        SHANG_HQ["金石商會總堂 (shanghui_hq)"]
        CARAVAN_YARD["遠行車馬大院 (caravan_yard)"]
        YARD_MAT["大料初堆棧 (yard_material)"]
        GRAIN_MKT["米糧行市 (grain_market)"]
        CANAL["青河漕運水關 (canal)"]
        WAREHOUSE_GRN["義倉常平窖 (warehouse_grain)"]

        MARKET_SPEC --- SHANG_HQ
        SHANG_HQ --- CARAVAN_YARD
        MARKET_SPEC --- YARD_MAT
        MARKET_SPEC --- GRAIN_MKT
        GRAIN_MKT --- CANAL
        GRAIN_MKT --- WAREHOUSE_GRN
    end

    %% ─────────────────────────────────────────────────────────────
    %% 7. 外城門戶、水門與官道
    %% ─────────────────────────────────────────────────────────────
    subgraph GateOuterSub["【城門門戶與郊道】"]
        GATE_E["金石東關 (gate_east)"]
        GATE_W["金石西關 (gate_west)"]
        GATE_S["金石南關 (gate_south)"]
        GATE_S_INN["南關車馬小棧 (gate_south_inn)"]
        FARMLAND["西郊官田 (farmland_w)"]
        IRRIGATION["引水渠壩 (irrigation)"]
        MOAT["護城河暗港 (moat)"]
        SOUTH_ROAD["南嶺官道 (south_road)"]

        GATE_S --- GATE_S_INN
        GATE_S --- SOUTH_ROAD
        GATE_W --- FARMLAND --- IRRIGATION
        FARMLAND --- MOAT
    end

    %% ─────────────────────────────────────────────────────────────
    %% 8. 巡城青石步道環線
    %% ─────────────────────────────────────────────────────────────
    subgraph WallLoopSub["【巡城步道與四方角樓】"]
        WALL_S["巡城南步道 (wall_path_s)"]
        WALL_E["巡城東步道 (wall_path_e)"]
        WALL_N["巡城北步道 (wall_path_n)"]
        WALL_W["巡城西步道 (wall_path_w)"]
        TOWER_S["南城哨樓 (wall_tower_s)"]
        TOWER_E["東關箭樓 (wall_tower_e)"]
        TOWER_W["西關譙樓 (wall_tower_w)"]

        WALL_S --- TOWER_E --- WALL_E
        WALL_E --- TOWER_N --- WALL_N
        WALL_N --- TOWER_W --- WALL_W
        WALL_W --- TOWER_S --- WALL_S
    end

    %% ─────────────────────────────────────────────────────────────
    %% 核心跨區連線
    %% ─────────────────────────────────────────────────────────────
    GATE_N_PLAZA --- GONG_GATE
    GONG_GATE --- SQUARE
    SQUARE --- MARKET_SPEC
    MARKET_SPEC --- GATE_S

    DAO_GATE --- SQUARE
    SQUARE --- WU_GATE

    GATE_W --- DAO_GATE
    WU_GATE --- GATE_E

    GATE_S --- WALL_S
    GATE_E --- WALL_E
    GATE_N --- WALL_N
    GATE_W --- WALL_W

    BLACK_ALLEY -.->|down 枯井暗道| UNDER_MARKET["【地下鬼市】 (城下暗渠)"]
    SOUTH_ROAD ---|southwest 450 里| HEISHIPU["往【黑石鋪】新手發跡地"]
```

---

## 🏛️ 房間清單與環境矩陣 (44 間都城房間)

| 分區 | 檔案路徑 | 名稱 | 濁氣指數 | 絕靈法網 | 核心 NPC / 機制 |
| :--- | :--- | :--- | :---: | :---: | :--- |
| **中央核心** | [`center/square.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/square.c) | 中央青石廣場 | 100% | 覆蓋 | 四通八達樞紐 |
| | [`center/yamen.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/yamen.c) | 金石府衙正堂 | 90% | 覆蓋 | 府尹文承敬、通緝與入籍 |
| | [`center/yamen_archive.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/yamen_archive.c) | 案牘庫 | 80% | 覆蓋 | 戶籍、地契密檔 |
| | [`center/yamen_prison.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/yamen_prison.c) | 府衙大牢 | 95% | 覆蓋 | 刑具、禁魔牢籠 |
| | [`center/granary.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/granary.c) | 官平糧倉 | 90% | 覆蓋 | 府城儲糧重地 |
| | [`center/academy.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/academy.c) | 流泉學塾 | 70% | 覆蓋 | 陸夫子、讀書識字 |
| | [`center/clinic.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/clinic.c) | 百草堂醫館 | 75% | 覆蓋 | 白芷醫師、療傷解毒、濁氣淨化 |
| | [`center/bank.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/bank.c) | 通寶錢莊 | 95% | 覆蓋 | 存提款、銀票匯兌 |
| | [`center/pawnshop.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/pawnshop.c) | 聚珍當鋪 | 95% | 覆蓋 | 賈掌櫃、典當淘寶 |
| | [`center/black_alley.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/black_alley.c) | 鬼市暗巷 | 90% | 死角 | 暗道枯井（通往城下鬼市） |
| | [`center/inn_main.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/inn_main.c) | 金石大客棧 | 100% | 覆蓋 | 歇腳恢復、客棧小二 |
| | [`center/post_station.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/center/post_station.c) | 官辦驛傳總所 | 95% | 覆蓋 | 官道通關文牒、急件快遞 |
| **百工總會** | [`north/gong_gate.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/north/gong_gate.c) | 百工總會大門 | 65% | 覆蓋 | 工匠守衛、物道入門指引 |
| | [`north/gong_registry.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/north/gong_registry.c) | 匠籍登記處 | 55% | 覆蓋 | 魯長生、考核與專利授權 |
| | [`north/gong_hall.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/north/gong_hall.c) | 天工殿堂 | 45% | 覆蓋 | 歐陽玄會長、轉職考核、墨玉尺 |
| | [`north/gong_forge.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/north/gong_forge.c) | 鍛鐵金石坊 | 50% | 覆蓋 | 莫大錘、兵甲鍛造 |
| | [`north/gong_wood.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/north/gong_wood.c) | 機巧木作坊 | 50% | 覆蓋 | 機巧傀儡、機關盒 |
| | [`north/gong_stone.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/north/gong_stone.c) | 精研石雕坊 | 50% | 覆蓋 | 符印基石、靈石打磨 |
| | [`north/gong_leather.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/north/gong_leather.c) | 百鞣皮甲坊 | 50% | 覆蓋 | 異獸鞣皮、輕甲防禦 |
| | [`north/gong_alchemy.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/north/gong_alchemy.c) | 丹丸物性坊 | 50% | 覆蓋 | 藥渣萃取、清心散合成 |
| | [`north/gong_fireworks.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/north/gong_fireworks.c) | 烈性火硝坊 | 50% | 覆蓋 | 硫礬火器、霹靂信號彈 |
| **宣道司** | [`west/dao_gate.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/west/dao_gate.c) | 宣道司山門 | 60% | 覆蓋 | 道童迎客、入觀法規 |
| | [`west/dao_hall.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/west/dao_hall.c) | 太虛三清殿 | 45% | 覆蓋 | 玄機真人、法道入門、引氣訣 |
| | [`west/dao_observatory.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/west/dao_observatory.c) | 摘星台 | 35% | 覆蓋 | 行遠道人、星宿推演、渾天鏡 |
| | [`west/dao_roof.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/west/dao_roof.c) | 聽經閣頂層 | 35% | 覆蓋 | 高層冥想、神識演練 |
| | [`west/dao_quiet.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/west/dao_quiet.c) | 清修靜室 | 40% | 覆蓋 | 闢穀定境、驅除心魔 |
| **鎮武軍鎮** | [`east/wu_gate.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/east/wu_gate.c) | 軍鎮大閘門 | 70% | 覆蓋 | 鐵甲衛士、軍紀盤查 |
| | [`east/wu_plaza.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/east/wu_plaza.c) | 演武大校場 | 60% | 覆蓋 | 霸山總教頭、力道轉職、黑鐵腰牌 |
| | [`east/wu_arena.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/east/wu_arena.c) | 黑鐵生死擂 | 65% | 覆蓋 | 趙猛裁判、切磋比武 |
| | [`east/wu_hall.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/east/wu_hall.c) | 偏將軍帳 | 60% | 覆蓋 | 軍令發布、大荒煞潮軍報 |
| | [`east/wu_armory.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/east/wu_armory.c) | 披甲兵器庫 | 65% | 覆蓋 | 軍鎮鐵戟、百煉玄鐵甲 |
| | [`east/wu_barracks.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/east/wu_barracks.c) | 鎮武兵營 | 65% | 覆蓋 | 駐軍歇息所 |
| **南部商貿** | [`south/market_special.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/south/market_special.c) | 六縣專材長街 | 100% | 覆蓋 | 六縣珍異特產交流 |
| | [`south/shanghui_hq.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/south/shanghui_hq.c) | 金石商會總堂 | 95% | 覆蓋 | 會長錢百川、商盟憑證 |
| | [`south/caravan_yard.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/south/caravan_yard.c) | 遠行車馬大院 | 95% | 覆蓋 | 商隊組織、鏢局招募 |
| | [`south/yard_material.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/south/yard_material.c) | 大料初堆棧 | 90% | 覆蓋 | 粗料卸載、初階分類 |
| | [`south/grain_market.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/south/grain_market.c) | 米糧行市 | 95% | 覆蓋 | 盤木大米、粗糧交易 |
| | [`south/canal.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/south/canal.c) | 青河漕運水關 | 80% | 覆蓋 | 水運貨船、擺渡碼頭 |
| | [`south/warehouse_grain.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/south/warehouse_grain.c) | 義倉常平窖 | 85% | 覆蓋 | 平抑物價、糧款備庫 |
| **城門外城** | [`gate/gate_south.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/gate/gate_south.c) | 金石南關 | 80% | 覆蓋 | 盤查守軍、南出官道大門 |
| | [`gate/gate_north.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/gate/gate_north.c) | 金石北關 | 75% | 覆蓋 | 迎風要道、出北荒門戶 |
| | [`gate/gate_east.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/gate/gate_east.c) | 金石東關 | 80% | 覆蓋 | 東出烈礬/濁水門戶 |
| | [`gate/gate_west.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/gate/gate_west.c) | 金石西關 | 75% | 覆蓋 | 西往青河門戶 |
| | [`outer/south_road.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/outer/south_road.c) | 南嶺官道 | 20% | 無 | 直通黑石鋪新手村（450里） |
| | [`outer/farmland_w.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/outer/farmland_w.c) | 西郊官田 | 15% | 無 | 城西郊野、百工藥田 |
| | [`outer/irrigation.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/outer/irrigation.c) | 引水渠壩 | 10% | 無 | 青河引水水利設施 |
| | [`outer/graveyard.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/outer/graveyard.c) | 亂葬義塚 | 10% | 無 | 北門外亂墳崗、陰煞初現 |
| | [`outer/post_depot.c`](file:///home/wade/src/github/mudscript/forgotten-space/d/city/outer/post_depot.c) | 外城大車馬店 | 60% | 無 | 北門外大宗牲畜車馬歇息地 |
