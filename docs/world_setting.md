# 《世界觀與 Mudlib 架構設定集》(World Setting & Mudlib Bible)

> **版本**：v0.1.0 (草創階段)  
> **更新時間**：2026-10-15  
> **目標**：作為小說創作的核心設定集，並同步作為 `./mudscript/` (LPC Mudlib) 的設計開發規格書。

---

## 目錄 (Table of Contents)
1. [基本資訊 (Overview & Meta)](#1-基本資訊-overview--meta)
2. [宇宙觀與歷史背景 (Cosmology & History)](#2-宇宙觀與歷史背景-cosmology--history)
3. [力量體系與修煉法則 (Power System & Mechanics)](#3-力量體系與修煉法則-power-system--mechanics)
4. [地理地圖與城鎮分區 (Geography & World Map)](#4-地理地圖與城鎮分區-geography--world-map)
5. [勢力宗門與陣營設定 (Factions & Sects)](#5-勢力宗門與陣營設定-factions--sects)
6. [核心人物檔案 (Character Profiles)](#6-核心人物檔案-character-profiles)
7. [小說大綱與章節規劃 (Novel Outline)](#7-小說大綱與章節規劃-novel-outline)
8. [Mudlib LPC 機制映射 (Mudlib LPC Mapping)](#8-mudlib-lpc-機制映射-mudlib-lpc-mapping)

---

## 1. 基本資訊 (Overview & Meta)

* **作品暫定名稱**：*(待討論決定)*
* **題材風格**：*(待討論決定，如：傳統東方修真 / 仙俠奇幻 / 本土神話奇幻 / 蒸氣科幻修仙等)*
* **核心基調 (Tone)**：*(例如：浩大蒼茫、江湖情義、殘酷爭渡、探尋失落真相等)*
* **核心衝突 (The Core Conflict)**：*(推動整個世界運轉與主角命運的核心矛盾)*

---

## 2. 宇宙觀與歷史背景 (Cosmology & History)

### 2.1 天地起源與構成
* 天地萬物由何種源質構成？（天地靈氣、元力、太初陰陽、魂靈碎片？）
* 天界、人間、深淵、幽冥的界限與結構。

### 2.2 歷史紀元 (Timeline / Epochs)
* **遠古/太古紀元**：傳說時代、上古神明或遠古劫難。
* **中古紀元**：宗門建立、道統傳承之爭。
* **當前時代**：故事開端的現狀、暗潮湧動的危機。

---

## 3. 力量體系與修煉法則 (Power System & Mechanics)

> 💡 **Mudlib 連動設計**：此處每個層級與屬性，將直接對應到 Mudscript 的屬性（Attributes）、心法技能（Skills）與戰鬥系統（Combat Daemon）。

### 3.1 境界劃分 (Progression Stages)
*(例如：九品制、傳統練氣/築基/金丹/元嬰，或獨創境界)*
1. **第一境界**：
2. **第二境界**：
3. **第三境界**：
4. **第四境界**：
5. **巔峰/化境**：

### 3.2 基礎屬性與能量池 (Attributes & Vitals)
* **生命/氣血 (HP / Kee)**：肉身抗性與生命活力。
* **精神/神識 (Sen / Spirit)**：感知力、悟性、抵禦心魔與幻術。
* **內力/真元 (Force / Mana)**：發動武學與法術的能量儲備。

### 3.3 功法流派與戰鬥哲學 (Skills & Combat Philosophy)
* **心法 (Force Skills)**：提升真元上限與恢復速度，決定屬性親和。
* **外功/招式 (Martial Arts)**：刀法、劍訣、掌法、身法步法。
* **秘術/神通 (Spells & Talents)**：陣法、符籙、煉丹、煉器、神識刺擊。

---

## 4. 地理地圖與城鎮分區 (Geography & World Map)

> 💡 **Mudlib 連動設計**：此處每個重要區域，將直接規劃為 Mudlib `d/<domain_name>/` 下的房間網絡。

### 4.1 宏觀世界版圖
* **中土/平原區**：文明中心、皇權或繁華商貿之都。
* **名山靈川**：各大名門正派的祖庭與洞天福地。
* **邊荒/黑市/法外之地**：散修、亡命之徒聚居之所。
* **禁地/上古秘境**：高風險高回報的冒險死地。

### 4.2 故事起點（新手村 / Starting Area）
* **地名**：
* **環境特徵**：
* **關鍵場所**：茶棚/客棧、破廟、武館、後山林地、幽谷。

---

## 5. 勢力宗門與陣營設定 (Factions & Sects)

> 💡 **Mudlib 連動設計**：各宗門對應 MUD 的入門門派導師、門派任務與獨門心法。

### 門派 A：*(名稱待定)*
* **陣營定位**：
* **宗門宗旨**：
* **代表武學**：
* **掌門 / 代表長老**：

### 門派 B：*(名稱待定)*
* **陣營定位**：
* **宗門宗旨**：
* **代表武學**：

---

## 6. 核心人物檔案 (Character Profiles)

### 6.1 主角 (Protagonist)
* **姓名**：*(待定)*
* **年齡 / 外觀**：
* **性格特質**：
* **出身背景**：
* **開局困境 (The Starting Conflict)**：
* **金手指 / 獨特機緣 (The Catalyst)**：
* **心靈目標與渴望**：

### 6.2 關鍵配角與同行者
* **領路人/導師**：
* **摯友/夥伴**：

### 6.3 主要反派與對立面
* **初期阻礙者**：
* **幕後宿敵**：

---

## 7. 小說大綱與章節規劃 (Novel Outline)

### 第一卷：破局 / 踏上歧途 *(卷名待定)*
* **第 1 章**：破曉之隙（開局情境、主角身份登場、突發事件打破平靜）
* **第 2 章**：抉擇與代價
* **第 3 章**：初試啼聲
* **第 4 章**：離鄉與遠行

---

## 8. Mudlib LPC 機制映射 (Mudlib LPC Mapping)

| 小說元素 | Mudlib 目錄路徑 | LPC 核心類別 / 物件 | 說明 |
| :--- | :--- | :--- | :--- |
| 主角 / NPC | `/std/char/npc.c` | `inherit NPC;` | 具有生命力、AI 反應、對話與戰鬥邏輯 |
| 新手村客棧 | `/d/start_town/inn.c` | `inherit ROOM;` | 玩家復活點、安全區、休息回血 |
| 門派武學 | `/daemon/skill/<skill_name>.c` | `inherit SKILL;` | 招式判定、冷卻時間、傷害倍率與 perform 絕招 |
| 宗門法寶 | `/clone/weapon/` | `inherit WEAPON;` | 裝備數值、特殊攻擊效果 |
| 主線任務 | `/daemon/questd.c` | `QUEST_D` | 劇情推動、獎勵發放、世界狀態觸發 |
