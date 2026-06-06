inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("女子雕像",({"statue"}));
    set("long","
一尊栩栩如生的女子雕像，從雕像的臉上，你可以感受到一種期待和盼望的神情
，似乎是在等待他的情郎能早日來與她相會，但再怎麼盼卻也盼不到他的來到，
你心中不禁同情心大發，一時突然想到說不定你可以用法術(cast)來召喚出她的
靈魂來...\n");
    set("unit","尊");
    set("value",100);
    set("no_get",1);
    set("no_sac",1);
    set("no_auc",1);
    set_weight(500000);
    setup();
}
void init()
{
        add_action("do_cast","cast");
        add_action("do_cast","co");
        add_action("do_cast","con");
        add_action("do_cast","conj");
        add_action("do_cast","conju");
        add_action("do_cast","conjur");
        add_action("do_cast","conjure");
}
int do_cast(string arg)
{
    object me = this_player();
        object ob = this_object();
        object fly = new("/open/mon/obj/soul");

    if(me->query_temp("icestorm/lovestory")==3
    && arg == "invocation on statue") {
        message_vision(HIW"$N喃喃地念了幾句咒語。"HIC"\n
一陣清風吹過，"HIM"蝶魂"HIC"乘雲緩緩從天而降。\n\n",me, ob);
        fly->move(environment(me));
        me->delete_temp("icestorm/lovestory");
        me->set_temp("icestorm/ice_spell",1);
        return 1;
    }
    else if(me->query("get_icestorm")==1
    && arg == "icestorm on statue") {
        message_vision("$N施展出剛習得的【冰雪風暴】，頓時一陣天搖地動，\n
只見瑞雪奏降，祥風清拂，一團白霧籠罩了雕像之後，隨之出現一名美麗的少婦...\n\n",me);
        message_vision("少婦向$N說道：多謝救命之恩，奴家當以畢身之功\力來協助$N...\n
說完便將雙掌置於$N的天靈蓋\，緩緩的輸入真氣...\n
$N只感到說不出的受用，張口欲言謝，卻吐不出半個字來...\n
突然間，少婦將手收回，說道：奴家已助$N成就【冰雪風暴】之頂級功\力，盼$N用於正途，就此告辭！\n\n
一陣白煙飄然而至，完全籠罩住少婦之後，又漸漸散去，那少婦已不知去向何方...\n"NOR,me);
        me->set("allow_icestorm",1);
        me->delete("get_icestorm");
        destruct(ob);
        return 1;
    }
    else return notify_fail("指令格式﹕cast <法術> [on <目標>]\n");
}
