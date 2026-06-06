 inherit NPC;

void create()
{
        set_name("大蛇", ({ "big snake","snake" }) );
        set("long",@LONG
一隻在山嶺間、草叢中隨處可見的青蛇，不過，體型卻比一般蛇
大上十倍以上，她不時吐出舌尖，彷彿眼前的你是她的美味食物一般
，必須隨時小心她攻擊你．．．
LONG);
        set("race","野獸");
        set("age", 20);
        set("str", 100);
        set("con", 100);
        set("max_gin", 600);
        set("max_kee", 600);
        set("max_sen", 600);
        set("limbs",({"蛇頭","蛇身","蛇尾"}));
        set("verbs",({"bite","dunt"}));
        set("combat_exp",3000);
        setup();
}

void die()
{
        object ob,winner,obj;

        ob = this_object();
        winner = ob->query_temp("last_damage_from");
        obj = new(__DIR__"snake-gall");

        if(!winner)
                ::die();
        if( random(100) < 30 )
        {
                message_vision("$N奮力一擊，$n的蛇膽被震出蛇身！\n",winner,ob);
                obj->move(environment(winner));
        }
        ::die();
}
