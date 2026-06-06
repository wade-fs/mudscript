 inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIR"蛇靈石"NOR,({"snake stone","snake","stone"}));
        set_weight(1000);
        if(clonep())
                set_default_object(__FILE__);
        else{
                set("base_unit","顆");
                set("value",1);
                set("long",@LONG
鮮紅色的石頭，彷彿鮮血一般的顏色，在最深紅的地方，似乎摻
雜著一種不可預支的深黑。
LONG);
                set("no_auc",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_put",1);
                set("no_sell",1);
        }
        setup();
}

void init()
{
add_action("do_catch","catch");
}

int do_catch(string arg)
{
        object me,ob,obj,str,room;
        string r01,r02;
        int i;

        ob = this_object();
        me = this_player();
        obj = new(__DIR__"snake-stone");
        r02 = "/open/area/house/h02";

        if(!arg)
                return 0;

        if(arg != "stone" && arg != "snake stone")
                return 0;

        if( random(100) < 35 )
        {
                message_vision(HIW"$N伸手一抓～迅速的將$n握在手中收在懷中。\n"NOR,me,ob);
                obj->move(me);
                ob->move(r02);
                present("iv xiu lian",environment(ob))->delete_temp("string");
                destruct(ob);
        }
        else
        {
                i = random(10);
                message_vision(HIY"正當$N準備出手抓取的那一瞬間，$n消失不見了！\n"NOR,me,ob);
                switch(i)
                {
                        case 0 :
                                r01 = "/open/quests/snake/r-68";
                                break;

                        case 1 :
                                r01 = "/open/fire-hole/f-34";
                                break;
                        case 2 :
                                r01 = "/open/start/room/startroom";
                                break;
                        case 3 :
                                r01 = "/open/main/room/maiu-5";
                                break;
                        case 4 :
                                r01 = "/open/wind-rain/a18";
                                break;
                        case 5 :
                                r01 = "/open/marksman/room/room2-2";
                                break;
                        case 6 :
                                r01 = "/open/gsword/star/room/star7";
                                break;
                        case 7 :
                                r01 = "/open/trans/room/room4";
                                break;
                        case 8 :
                                r01 = "/open/capital/room/king/saint-temple";
                                break;
                        case 9 :
                                r01 = "/open/port/room/r2-5";
                                break;
                        default :
                                r01 = "/open/area/house/h02";
                                break;
                }
                ob->move(r01);
                str = environment(ob);
                ob->set_temp("string",str->query("long"));
                ob->move(r02);
                present("iv xiu lian",environment(ob))->set_temp("string",ob->query_temp("string"));
                ob->move(r01);
        }
return 1;
}
