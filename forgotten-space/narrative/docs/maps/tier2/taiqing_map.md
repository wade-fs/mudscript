# 太清玄天宮地圖

> 狀態：`Act 1–2 implemented (7 房)` + `Act 3+ draft`。第三卷第一至二幕（Ch. 86、91–92）核心節點已於 `/d/sects/taiqing/*.c` 實裝並通過雙向連線與 `quest_audit.py`、`test_v3_act2.c` 驗證；宗門更深處（如 `thunder_talisman_hall`、`sealed_observatory`）仍為 `draft`。
>
> **拓撲修正（依 Ch. 91–92 正文）**：`hidden_archive`（藏星秘閣）開鑿於天柱峰背陰山腹，由 `star_law_hall` 向北直通；`quiet_peak`（清修偏峰）通往後山新增之 `ascension_platform`（升仙台石築靈堂）。

## 房間與拓撲

| Room ID | 顯示名稱 | 建議／實裝路徑 | 主要出口 | 用途／限制（Act 1–2 共 7 房已實裝） |
|---|---|---|---|---|
| `gate` | 太清玄天宮・登天雲梯山門 | `/d/sects/taiqing/gate.c` | `south`→`/d/yunjin/wanshan_square.c`、`north`→`outer_court` | 〔實裝，Ch. 86〕三百六十五階問心陣（動作 `measure ladder`）；駐點：`lu_guanlan`（陸觀瀾） |
| `outer_court` | 太清玄天宮・外門雲舍 | `/d/sects/taiqing/outer_court.c` | `south`→`gate`、`north`→`star_law_hall` | 〔實裝，Ch. 86〕外門居所、功課與同門競技；駐點：`shen_zhaochen`（沈照塵） |
| `star_law_hall` | 太清玄天宮・周天星律院 | `/d/sects/taiqing/star_law_hall.c` | `south`→`outer_court`、`north`→`hidden_archive`、`east`→`outer_observatory`、`northeast`→`quiet_peak` | 〔實裝，Ch. 86、91〕星曆校讀、測算與實證封存；駐點：`song_zhiwei`（宋知微） |
| `hidden_archive` | 太清玄天宮・藏星秘閣 | `/d/sects/taiqing/hidden_archive.c` | `south`→`star_law_hall` | 〔實裝，Ch. 91〕天柱背陰花崗岩山腹；《紫微星官錄》三版本與蟲蛀舊箱廢頁（動作 `collate archive`）；駐點：`yu_shouzhuo`（余守拙） |
| `outer_observatory` | 太清玄天宮・天柱觀星台 | `/d/sects/taiqing/outer_observatory.c` | `west`→`star_law_hall`、`north`→`quiet_peak` | 〔實裝，Ch. 91〕黃銅渾儀朔望雙向盲測與暴雪氣壓誤差校驗（動作 `observe sphere`） |
| `quiet_peak` | 太清後山・清修偏峰 | `/d/sects/taiqing/quiet_peak.c` | `southwest`→`star_law_hall`、`south`→`outer_observatory`、`north`→`ascension_platform` | 〔實裝，Ch. 92、111〕老松亭與簡素真人崖壁柴扉石屋；駐點：`jian_su`（簡素真人）、`yuan_qing`（元青，Lv.73 早期晶化弟子） |
| `ascension_platform` | 太清偏峰・升仙台石築靈堂 | `/d/sects/taiqing/ascension_platform.c` | `south`→`quiet_peak` | 〔實裝，Ch. 92 新增〕鶴鳴真人玉化晶像與主聚星抽取陣紋（動作 `collect crystal`）；駐點：`xuan_ming`（玄冥真人） |
| `thunder_talisman_hall` | 太清雷符殿 | `/d/sects/taiqing/thunder_talisman_hall.c` | `draft` | 〔draft〕雷符訓練、護山陣維護與執法調度 |
| `sealed_observatory` | 封存觀測室 | `/d/sects/taiqing/sealed_observatory.c` | `draft`（區域出口／劇情門禁） | 〔draft〕劇情門禁（Ch. 124）；保管被封存的異常觀測檔案 |

## 區域連線圖

```mermaid
flowchart TD
  gate["登天雲梯山門<br/>gate (實裝)"]
  outer_court["外門雲舍<br/>outer_court (實裝)"]
  star_law_hall["周天星律院<br/>star_law_hall (實裝)"]
  hidden_archive["藏星秘閣<br/>hidden_archive (實裝)"]
  outer_observatory["天柱觀星台<br/>outer_observatory (實裝)"]
  quiet_peak["清修偏峰<br/>quiet_peak (實裝)"]
  ascension_platform["升仙台石築靈堂<br/>ascension_platform (實裝)"]
  thunder_talisman_hall["太清雷符殿<br/>thunder_talisman_hall (draft)"]
  sealed_observatory["封存觀測室<br/>sealed_observatory (draft)"]
  gate --> outer_court
  outer_court --> star_law_hall
  star_law_hall --> hidden_archive
  star_law_hall --> outer_observatory
  star_law_hall --> quiet_peak
  outer_observatory --> quiet_peak
  quiet_peak --> ascension_platform
  star_law_hall -.-> thunder_talisman_hall
  outer_observatory -.-> sealed_observatory
```

## 房間設計規則

- 一般房間不得直接跳過中間節點連到禁地。
- 需要宗門令牌、軍令、商埠印信或任務狀態的門禁，必須明確記錄拒絕原因。
- 天候、獸潮、地煞污染可改變房間狀態，但不能無記錄地改變靜態出口。
- NPC 常駐房間以 `tier2_npc_roster.md` 與人物檔為準；出場時間表於第二階段補充。
- 此圖不代表遊戲已實裝。
