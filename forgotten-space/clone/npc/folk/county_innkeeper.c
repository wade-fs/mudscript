// clone/npc/folk/county_innkeeper.c
// 六縣地方客棧夥計／店小二（依所在縣城自動呈現風土與飲食互動）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("客棧夥計");
    set_short(CYN "地方客舍" NOR " 客棧夥計");
    set_long("一位肩搭白粗布巾、手腳勤快的地方客棧夥計。\n"
             "他整日迎來送往過路商旅與本鄉苦力，對當地井水甘苦、糧價漲落與客商口風瞭若指掌。\n");
    set_id(({ "innkeeper", "waiter", "xiaoer", "店小二", "客棧夥計", "夥計" }));

    setup_archetype("J", 6);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "inn", "info" }));
    set("no_combat", 1);

    add_response(({ "吃食", "湯水", "茶水", "歇腳", "drink", "rest" }),
        "夥計擦了擦桌案笑道：「客官遠道而來辛苦了！這兒備著本地熱湯粗茶，直接在屋裡『rest』或『drink』便能歇腳解乏，比外頭風沙強多啦！」");
    add_response(({ "木排", "備飯", "木客", "放排" }),
        "夥計麻利地記上帳本點頭：「林四那批木排已經綁妥啦？好好好，我這就吩咐灶房蒸兩籠大饅頭配臘肉湯，等押車人手一來管夠！」");
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object env = environment(this_object());
    string cid = env ? env->query_county() : "";
    object ws = load_object(WORLD_STATE_D);
    mapping st = (ws && cid != "") ? ws->query_county_status(cid) : 0;

    if (topic == "此地" || topic == "風土" || topic == "地方" || topic == "縣城" || topic == "特色") {
        string specialty = "熱茶粗餅";
        if (cid == "liefan") specialty = "南嶺甘泉熬的解毒綠豆湯（這兒泉水帶硫磺礦酸，礦工離不開它）";
        else if (cid == "qinghe") specialty = "現採洗靈草葉泡的清苦花茶與河鮮糙米粥";
        else if (cid == "panmu") specialty = "焙火松針粗茶與烤野菌乾饃";
        else if (cid == "zhenfeng") specialty = "滾燙羊雜胡椒熱湯（北塞朔風割人，沒這口熱湯暖不過夜）";
        else if (cid == "zhongshi") specialty = "炒大麥茶配厚實死麵餅子，石匠扛大石最頂餓";
        else if (cid == "zhuoshui") specialty = "老薑驅瘴濃湯配烤泥螺乾，不喝兩碗準染沼澤寒濕";

        string status_line = mapp(st)
            ? sprintf("眼下本縣專材行情已到 %d%%，店裡柴米油鹽也跟著水漲船高。", st["price_pct"])
            : "近來往來客商起落不定，大家都在看金石府城臉色過日子。";
        tell_object(me, query_name() + " 甩了甩搭在肩頭的粗布巾笑道：「我們這小店主打" + specialty + "。" + status_line + "」\n");
        return 1;
    }

    if (topic == "行情" || topic == "物價" || topic == "世道") {
        if (mapp(st)) {
            tell_object(me, query_name() + sprintf(" 嘆口氣壓低聲音道：「%s——這兒%s牌價都到 %d%% 了，連拉車苦力都快買不起新草鞋！」\n",
                st["stage_desc"], st["commodity"], st["price_pct"]));
            return 1;
        }
    }

    return ::do_chat(me, topic);
}
