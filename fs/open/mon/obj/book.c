inherit ITEM;
#include <ansi.h>
inherit F_AUTOLOAD;

void create()
{
    set_name(HIW + "冰封秘咒" + NOR,({"ice_spell book","book"}));
    set("long","
一本老舊的古書，裡面似乎隱藏著什麼神秘的法術，你可以試著修習(studying)一番...
        \n");
    set("unit","本");
    set("value",100);
    set("no_give",1);
    set("no_drop",1);
    set("no_steal",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sac",1);
    set("no_auc",1);
    set_weight(50);
    setup();
}
int query_autoload() { return 1; }
void init()
{
        add_action("do_learn","studying");
}

int do_learn(string arg)
{
        object me = this_player();
        object ob = this_object();
        
        if(me->query("get_book")==1) {
    if(!id(arg)) return notify_fail("你想修習什麼東西？\n");
    if(me->is_busy() || me->is_fighting())
                return notify_fail("你這會兒忙的沒時間修習冰封秘咒唷！\n");
        if((int)me->query("force") < 300)
                return notify_fail("你的經驗值不足以修習這門冰封秘咒！\n");
        if((int)me->query("combat_exp") < 5000000)
                return notify_fail("你的經驗值不足以修習這門冰封秘咒！\n");
        if(me->query_temp("icespell/learning")==1)
                return notify_fail("你正在修習這門冰封秘咒ㄚ！\n");
    if((int)me->query("gin") < 100 || (int)me->query("sen") < 100)
                return notify_fail("你沒有足夠的精神來修習這門冰封秘咒！");
    if(me->query("class")!="taoist")
                return notify_fail("你的職業不能修習這門冰封秘咒！");
        if(me->query_temp("icestorm/ice_spell")==7)
                return notify_fail("你應該先看看那封信吧！");
                message_vision(HIY + "$N屏氣凝神，心專眼注的盯著「$n" + HIY + "」仔細的參悟其中的奧妙～\n" + NOR,me, ob);
                me->set_temp("icespell/learning",1);
                call_out("learning",20+random(10), me);
                return 1;
        }
}
int learning(object me)
{
    object ob = this_object();
    int sub = 50+random(50);
    int time = (int)me->query("icespell/time");
    time = 200-time;

    if(me->query_temp("icespell/learning")==1)
  {
    if((int)me->query("force") < 300 || (int)me->query("sen") < 100 || (int)me->query("gin") < 100)
    {
        message_vision(HIB + "由於$N的精神及內力不夠，於是完全無法靜心參看「$n" + HIB + "」的內容...\n",me, ob);
                me->delete_temp("icespell/learning");
        return 1;
    }
        if(time == 195) {
                message_vision("$N努力的參透了『$n』的" + HIC + "《第一章》" + HIM + "「薄霧形冰」" + NOR + "！\n",me, ob);
                me->delete_temp("icespell/learning");
                me->add("icespell/time",1);
                return 1;
        }
        else if(time == 180) {
                message_vision("$N努力的參透了『$n』的" + HIC + "《第二章》" + HIG + "「細雨降冰」" + NOR + "！\n",me, ob);
                me->delete_temp("icespell/learning");
                me->add("icespell/time",1);
                return 1;
        }
        else if(time == 155) {
                message_vision("$N努力的參透了『$n』的" + HIC + "《第三章》" + HIB + "「珠露結冰」" + NOR + "！\n",me, ob);
                me->delete_temp("icespell/learning");
                me->add("icespell/time",1);
                return 1;
        }
    else if(time == 125) {
                message_vision("$N努力的參透了『$n』的" + HIC + "《第四章》" + HIY + "「寒霜成冰」" + NOR + "！\n",me, ob);
                me->delete_temp("icespell/learning");
                me->add("icespell/time",1);
                return 1;
        }
    else if(time == 85) {
                message_vision("$N努力的參透了『$n』的" + HIC + "《第五章》" + HIR + "「凌雲化冰」" + NOR + "！\n",me, ob);
                me->delete_temp("icespell/learning");
                me->add("icespell/time",1);
                return 1;
        }
    else if(time == 50) {
                message_vision("$N努力的參透了『$n』的" + HIC + "《第六章》" + HIW + "「皚雪凝冰」" + NOR + "！\n",me, ob);
                me->delete_temp("icespell/learning");
                me->add("icespell/time",1);
                return 1;
        }
    else if(time == 0) {
                message_vision(HIY + "$N經過一番努力的參透，終於悟得了『$n" + HIY + "』的真理，習得了奧義秘招" + HIW + "【冰雪風暴】" + NOR + "！！！\n",me, ob);
                me->delete("get_book");
                me->delete("icespell/time");
                me->delete_temp("icespell/learning");
                me->set("get_icestorm",1);
                destruct(ob);
                return 1;
    }
    else {
                message_vision(HIC + "$N努力的耗費精神參讀「$n" + HIC + "」的內容，似乎又有了一些新的體悟...\n" + NOR,me, ob);
                me->add("icespell/time",1);
                me->add("gin",-sub);
                me->add("sen",-sub);
                me->add("force",-300);
                me->delete_temp("icespell/learning");
                return 1;
        }
  }
}
        
