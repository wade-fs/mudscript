// /d/sects/taiqing/ark_portal_chamber.c
// 三山祖庭地底・太古破界方舟主傳送室 (Ch.126：五座石台技術校驗與單向開啟三丈青金星門)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("祖庭地底・太古破界方舟主傳送室");
    set_long("沿三大名山萬仞山腹三礦交擠而成的陡峭深黑螺旋階梯下行千餘丈，豁然顯出一座\n"
             "可容千人的宏偉地下球形大殿。與北荒裂谷破損漏液的冷卻艙段迥異，此處由半透明\n"
             "黑曜玄石拼接穹頂、保存完好；正中央矗立高逾三丈、刻滿雙重逆星軌道與幾何齒輪的\n"
             "巨型環狀空間傳送門框，前方依次排列五座驗證石台：正北水銀星盤控台、東北傳動主台、\n"
             "西北黑岩陣台、西南高壓點火閥門台，與正南行商總約驗證石碑（指令：activate gate）。\n"
             "門扉啟動後須於外陣崩裂前最後一息入陣（enter gate）；向上攀登螺旋黑階返【封存觀測室】。\n");

    set_exits(([
        "up": "/d/sects/taiqing/sealed_observatory.c",
    ]));

    set("is_outdoor", 0);
}

void init() {
    ::init();
    add_action("do_activate", "activate");
    add_action("do_enter", "enter");
}

int do_activate(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "gate" && arg != "portal" && arg != "array" && arg != "古陣" && arg != "五器") {
        notify_fail("你想啟動哪座核心古陣？試試：activate gate\n");
        return 0;
    }
    message_vision(HIC "頭頂千丈地脈在十丈紫黑滅世神雷轟擊下劇烈震顫，宋知微握定星盤大呼催促！\n"
                       "・正北主控台：以【逆星拓片】扣合水銀星象凹盤，釘定跨界座標向量！\n"
                       "・東北傳動台：左握阿鐵卡尺確認微米偏移，嵌【不融黑鐵齒輪】鎖死撕裂應力！\n"
                       "・西北陣台：【獵獸圖騰骨片】按入黑岩，長呼吸共振展開生命屏蔽場！\n"
                       "・西南閥門台：【古礦晶核殘片】配溫和藥靈生機點火燃起儲備靈石總庫！\n"
                       "・正南主驗證台：【天門引】與【九城總契銅版】合印造冊物資證物，青金長鳴響徹大殿——\n"
                       "足有三丈高、旋轉浩瀚星霧的單向青金星門應聲撕開（可輸入 enter gate 踏入洞天）！\n" NOR, me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "activate", "target": "gate" ]));
    }
    return 1;
}

int do_enter(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "gate" && arg != "portal" && arg != "star" && arg != "星門" && arg != "洞天") {
        notify_fail("你想踏入哪處傳送光門？試試：enter gate\n");
        return 0;
    }
    object dst = load_object("/d/realm/peach_plateau.c");
    if (!dst) {
        tell_object(me, "星門另一端的空間座標尚在穩定中。\n");
        return 1;
    }
    message_vision(HIW "$N在護山大陣徹底崩碎前的最後一息邁進旋轉星霧！身後紫黑滅世雷火將主傳送室\n"
                       "連同五座石台盡數劈成廢墟煙塵，單向空間裂隙從此徹底閉合……\n" NOR, me);
    me->move(dst);
    return 1;
}
