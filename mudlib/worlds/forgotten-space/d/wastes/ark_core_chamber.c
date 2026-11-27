// /d/wastes/ark_core_chamber.c
// 太古破界方舟・八角形主陣基核心圓台（Ch.106-107：五遺物嵌入式凹龕多階段校驗與殘缺太古光影紀錄）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

mapping core_slots;

void reset_core_slots() {
    core_slots = ([
        "north": 0,
        "northeast": 0,
        "northwest": 0,
        "southwest": 0,
        "south": 0
    ]);
}

void create() {
    ::create();
    reset_core_slots();
    set_short("太古方舟・八角形主陣基核心圓台");
    set_long("高出艙底地面三丈、直徑約十丈的八角形暗銀冷硬金屬圓台，台面刻滿幾何凹槽與\n"
             "星軌導流線。中央多邊形晶石底座周圍環列正北、東北、西北、西南、正南五個對應不同\n"
             "紋路的嵌入式凹龕——可依序逐一嵌入校驗（place north | northeast | northwest | southwest | south，或 status）：\n"
             "  【逆星斷碑拓片】、【不融黑鐵齒輪】、【獵獸圖騰骨片】、【古礦地煞晶核殘片】與【天門引暨青銅契版】。\n"
             "亦可在齊備後直接執行五器共鳴總嵌（place relics）。\n"
             "圓台後方暗沉合金門廊微滑半尺通往【方舟後勤石鋼廳室】，向南走下【方舟主引擎冷卻艙段】。\n");

    set_exits(([
        "south": "/d/wastes/ark_foundation.c",
        "north": "/d/wastes/ark_logistics_hall.c",
    ]));

    set("is_outdoor", 0);
    set_touch("default", HIC "你伸手撫過八角形暗銀金屬圓台，台面幾何凹槽的加工精度達到微米級，五個嵌入式凹龕內壁分別刻著星軌、齒輪、骨紋、晶簇與青金契印。" NOR);
    set_smell("default", CYN "艙室裡瀰漫著封存萬載的惰性冷卻液氣味與淡淡的金屬電離氣息。" NOR);
    set_listen("default", WHT "圓台底部傳來極其微弱的殘餘電容脈衝聲，彷彿整座沉睡的方舟正等待五器歸位校驗。" NOR);
}

void init() {
    ::init();
    add_action("do_place", "place");
    add_action("do_core_status", "status");
}

mapping query_core_slots(object me) {
    if (!core_slots) reset_core_slots();
    if (me && mapp(me->query_temp("ark_core_slots"))) {
        return copy(me->query_temp("ark_core_slots"));
    }
    return copy(core_slots);
}

int query_core_placed_count(object me) {
    mapping st = query_core_slots(me);
    int cnt = 0;
    foreach (string k in ({ "north", "northeast", "northwest", "southwest", "south" })) {
        if (st[k]) cnt++;
    }
    return cnt;
}

int do_core_status(string arg) {
    object me = this_player();
    mapping st = query_core_slots(me);
    tell_object(me, sprintf(HIW "\n【方舟核心圓台凹龕嵌入進度：%d / 5】\n" NOR
                            "  正北星軌龕: %s | 東北齒輪龕: %s | 西北骨紋龕: %s\n"
                            "  西南晶核龕: %s | 正南契印龕: %s\n",
                            query_core_placed_count(me),
                            st["north"] ? HIG "就緒" NOR : YEL "待嵌" NOR,
                            st["northeast"] ? HIG "就緒" NOR : YEL "待嵌" NOR,
                            st["northwest"] ? HIG "就緒" NOR : YEL "待嵌" NOR,
                            st["southwest"] ? HIG "就緒" NOR : YEL "待嵌" NOR,
                            st["south"] ? HIG "就緒" NOR : YEL "待嵌" NOR));
    return 1;
}

int do_place(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (!core_slots) reset_core_slots();

    string t = arg ? lower_case(arg) : "";
    if (t == "reset") {
        reset_core_slots();
        me->set_temp("ark_core_slots", copy(core_slots));
        tell_object(me, CYN "你從核心圓台凹龕逐一收回五器信物，準備重新嵌入校驗。\n" NOR);
        return 1;
    }

    if (t == "north" || t == "northeast" || t == "northwest" || t == "southwest" || t == "south") {
        mapping st = query_core_slots(me);
        if (t == "northeast" && !st["north"]) {
            tell_object(me, HIR "【嵌合失敗 — 星軌相位未定】請先於正北星軌龕 (place north) 嵌入逆星斷碑拓片確立基準軸，否則東北齒輪龕卡榫會自動反彈鎖死！\n" NOR);
            return 1;
        }
        if ((t == "northwest" || t == "southwest") && (!st["north"] || !st["northeast"])) {
            tell_object(me, HIR "【嵌合失敗 — 主軸應力未鎖】須先完成正北 (north) 與東北 (northeast) 兩座凹龕固定，方可置入生命與能源載體！\n" NOR);
            return 1;
        }
        if (t == "south" && (!st["north"] || !st["northeast"] || !st["northwest"] || !st["southwest"])) {
            tell_object(me, HIR "【嵌合失敗 — 總約授權迴路未閉合】正南契印龕必須在四方位信物全部點亮後，方能壓入天門引與青銅契版！\n" NOR);
            return 1;
        }
        st[t] = 1;
        core_slots[t] = 1;
        me->set_temp("ark_core_slots", st);
        tell_object(me, sprintf(HIG "你將對應太古信物穩穩壓入【%s】凹龕，導流紋路亮起一線穩定的青金冷光（%d / 5）！\n" NOR,
                                t, query_core_placed_count(me)));
        if (query_core_placed_count(me) < 5) return 1;
        t = "relics";
    }

    if (t != "relics" && t != "five" && t != "五器" && t != "遺物") {
        notify_fail("你想把什麼嵌入圓台凹龕？試試：place north / northeast / northwest / southwest / south 或 place relics\n");
        return 0;
    }

    core_slots = ([ "north": 1, "northeast": 1, "northwest": 1, "southwest": 1, "south": 1 ]);
    me->set_temp("ark_core_slots", copy(core_slots));
    message_vision("$N依序將五組太古信物嵌入東北、正北、西北、西南與正南凹龕！底座上方三尺處\n"
                   "隨即浮現青金色半透明光影：漆黑星海上懸著「二十八宿天羅結構」，下方人族方舟正由\n"
                   "『領航演算部』、『破陣護衛部』與『工程造物部』協同建造——然而影像跳至點火撞擊與\n"
                   "大清洗前瞬即炸出漆黑雪花噪點熄滅，唯見圓台後方合金門廊悄然滑開半尺縫隙！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "place", "target": "relics" ]));
    }
    return 1;
}
