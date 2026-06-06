// Room: /open/death/gate.c
#include <ansi.h>
#include <login.h>
inherit ROOM;
#include <basic_skill.h>

void end_death(object me);
void create ()
{
  set ("short", "陰曹入口");
  set ("long", @LONG
你已經來到了陰間的入口。雖然距離地府還有一段距離，但是你已經
感受到陣陣刺骨的陰風。四周一片荒涼，但是卻鬼影幢幢，看來這邊的夜
總會蠻熱鬧的，應該不愁沒伴。南邊和上面好像是和人世間相通的管道，
不過好像有一股無形的力量隔開這兩個不同的世界，看來要從這兩個方向
回去不是那麼簡單的事情。
LONG);

set("no_fight",1);
  set("exits", ([ /* sizeof() == 3 */
//  "up" : "/open/common/room/inn",
//  "south" : "/open/common/room/inn",
  "north" : __DIR__"bridge1",
]));
  set("no_auc",1);
  set("no_fight", 1);
  set("light_up", 1);
  set("no_transmit", 1);

  setup();
}

int valid_leave(mixed me, string dir)
{
        int i;
        string room;

        if (dir == "south") {
                i = (int)me->query_temp("back_road");
                i = i + 1;
                if (i >= (random(5) + 5)) {
                    me->set_temp("back_road", 10);
                    return notify_fail("你真的那麼想回家嗎？  好吧！！就如你所願，不過要付出很大的代價喔！！\n想清楚了之後， 如果還是要回去的話就往上面走吧！！\n");
                } else {
                        me->set_temp("back_road",i);
                        return notify_fail("你還想回家？進了地府就沒有路可退了！\n");
                }
        }
        else if (dir == "north") {
                me->delete_temp("back_road");
                return 1;
                }
        else if (dir == "up" || dir == "上面")
        {
            if ( (int) me->query_temp("back_road") >= 10 )
            {
                end_death(me);
                me->delete_temp("back_road");
                me->reincarnate();
                if(!stringp(room = me->query("startroom")))
                    room = STARTROOM;
                me->move(room);
                message_vision(
                "突然天中降下一團祥光，令人無法用肉眼直視。\n過了一會兒，祥光散去，一道人影出現，$N終於從陰間偷跑回來了。\n",me);
                return notify_fail("恭禧你又重回人世了。\n");
            } else
                return notify_fail("想回去！？ 沒那麼簡單！！\n");
        }
        else
        return 1;
}

void auto_revive(object ob)
{
        end_death(ob);
        ob->reincarnate();
        ob->move(REVIVEROOM);
        tell_object(ob, "閻羅王看你不爽啦！！送你回人間！！\n");
}
//增加記錄玩家的死亡，以免每次都有人說是莫名其妙的死了 by bss
void start_death(object ob)
{
        string str="";
        object fighter;

        if(ob->query_temp("last_damage_from"))
        {
                fighter=ob->query_temp("last_damage_from");
                str=ob->query("name")+"被"+fighter->query("name")+"所殺在"+ctime(time())+"\n";
                write_file("/open/death/death_record", str);
        }
        if(ob->query("combat_exp"))
        ob->set("death/combat_exp", 1);
        ob->add("death/time", 1);
        ob->set("death/skill", 1);
        if( ob->query("max_force") || ob->query("max_mana") || ob->query("max_atman") )
        {
        if( ob->query("max_force") >= ob->query("max_mana")
        && ob->query("max_force") >= ob->query("max_atman") )
        ob->set("death/force", 1);
        else if( ob->query("max_mana") >= ob->query("max_force")
        && ob->query("max_mana") >= ob->query("max_atman") )
                ob->set("death/mana", 1);
        else
                ob->set("death/atman", 1);
        }
//      call_out("auto_revive", 300, ob);
}

void end_death(object me)
{
        int cost;
        mapping skl, map;
        string *sname, *mapped;
        int i;

/*先關掉以前的fs算的值不合理...
    if( me->query("death/combat_exp") )
    {
        // cost =(int) ( me->query("combat_exp") *
// int 和 str 高的人得實戰經驗比較快... so 扣比較多... 5% - 10%
//       ( (random(me->query_int()*2 + me->query_str() - 30) + 60) / 12 ) /
// kar 比較高的人.. 比較有福氣... 可以打折... 除以 1 - 2....
//        ( random(me->query_kar() - 10) / 15 + 1) / 100 );
        cost = me->query("combat_exp") / 100 * 7;

        me->add("combat_exp", -cost);
        tell_object(me, "你的實戰經驗被扣了"+chinese_number(cost)+"點。\n");
    }
    if( me->query("death/skill") )
    {
        skl = me->query_skills();
        if(sizeof(skl)) {
            sname  = keys(skl);
            map = me->query_skill_map();
            if( mapp(map) ) mapped = values(map);
            if( !mapped ) mapped = ({});
            for(i=0; i<sizeof(skl); i++)
            if((member_array(sname[i], mapped) != -1 ) || (sname[i] == basic_skill[sname[i]]) )
            {
                if (random(me->query_kar()-10) < 15)
                {
                cost = (int) ( skl[sname[i]] *
// int 較高者得 skill 比較快... so 扣比較多..  1% - 4%
                ((random(me->query_int()) + 10) / 10 ) /
// 福緣較高者.. 扣較少.. 除以 1 - 2
                (random(me->query_kar() - 1) / 20 + 1) / 100 );
                skl[sname[i]] -= cost;
                tell_object(me, "你的"+to_chinese(sname[i])+"技巧被扣了"+chinese_number(cost)+"點。\n");
                }
            }
        }
    }


    if( me->query("death/force") )
    {
        cost = (int) ( me->query("max_force") *
// con 較高者得 force 比較快... so 扣比較多..  2% - 5%
        ((random(me->query_con()) + 20) / 10 ) /
// 福緣較高者.. 扣較少.. 除以 1 - 2
        (random(me->query_kar() - 10) / 20 + 1) / 100 );
        if( cost > 10)
          cost = 10;
        me->add("max_force", -cost);
        tell_object(me, "你的內力上限被扣了"+chinese_number(cost)+"點。\n");
    }
    if( me->query("death/mana") )
    {
        cost = (int) ( me->query("max_mana") *
// spi 較高者得 mana 比較快... so 扣比較多..  2% - 5%
        ((random(me->query_spi()) + 20) / 10 ) /
// 福緣較高者.. 扣較少.. 除以 1 - 2
        (random(me->query_kar() - 10) / 20 + 1) / 100);
        if( cost > 10)
          cost = 10;
        me->add("max_mana", -cost);
        tell_object(me, "你的法力上限被扣了"+chinese_number(cost)+"點。\n");
    }
    if( me->query("death/atman") )
    {
        cost = (int) ( me->query("max_atman") *
// spi 較高者得 靈力 比較快... so 扣比較多..  2% - 5%
        ((random(me->query_spi()) + 20) / 10 ) /
// 福緣較高者.. 扣較少.. 除以 1 - 2
        (random(me->query_kar() - 10) / 20 + 1) / 100 );
        if( cost > 10)
          cost = 10;
        me->add("max_atman", -cost);
        tell_object(me, "你的靈力上限被扣了"+chinese_number(cost)+"點。\n");
    }
*/

  me->delete("death");
}
