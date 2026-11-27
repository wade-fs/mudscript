// clone/npc/folk/chen_grain_owner.c
// 陳老漢・黑石鋪陳記雜糧鋪店主（平凡鄰里日常與市井糧價線） (Ch.1-38)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("陳老漢");
    set_short(YEL "陳記雜糧鋪" NOR " 陳老漢");
    set_long("一位背微駝、圍裙上總沾著燕麥麵與糙米糠灰的精瘦老人。\n"
             "他在黑石鋪經營這家小雜糧鋪三十多年，對誰家揭不開鍋、誰家婚喪嫁娶都一清二楚。\n");
    set_id(({ "chen_grain_owner", "old chen", "chen laohan", "陳老漢", "糧鋪掌櫃" }));

    setup_archetype("H", 7);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "shop", "info" }));
    set("no_combat", 1);

    add_response(({ "米價", "糧食", "粗鹽", "生意" }),
        "陳老漢撥了撥掛在木桿秤上的秤砣嘆道：「往年秋後糙米不過八文一斗，如今大荒商道一卡，鹽價漲了三倍，連村頭王大嬸都改摻樹皮煮粥啦。」");
    add_response(({ "送糧", "幫忙", "孤寡", "差事" }),
        "陳老漢抹了把臉上的糠灰點頭：「你要是肯搭把手，幫我先把櫃前那袋糙米過秤 (weigh grain)，再送往南邊溪灘給洗衣的王大嬸與村尾土地廟的孤寡老弱，老漢給你備份熱饃跟五十文工錢！」");
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object ws = load_object(WORLD_STATE_D);
    if (topic == "商隊" || topic == "存糧") {
        if (ws && ws->is_caravan_arrived()) {
            tell_object(me, query_name() + " 眉開眼笑：「商會大車總算進村了！粗鹽跟新麥都補上了，鄉親們總算不用餓肚子。」\n");
            return 1;
        }
        tell_object(me, query_name() + " 望著空蕩蕩的米缸發愁：「商隊再不來，陳記這幾袋底糧也撐不了幾日了。」\n");
        return 1;
    }
    return ::do_chat(me, topic);
}
