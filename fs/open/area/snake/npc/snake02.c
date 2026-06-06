 inherit NPC;

void create()
{
        set_name("黑蛇", ({ "black snake","snake" }) );
        set("long",@LONG
一隻在山嶺間、草叢中隨處可見的黑蛇．
LONG);
        set("race","野獸");
        set("age", 2);
        set("str", 20);
        set("con", 20);
        set("max_gin", 260);
        set("max_kee", 260);
        set("max_sen", 260);
        set("limbs",({"蛇頭","蛇身","蛇尾"}));
        set("verbs",({"bite"}));     
        set("combat_exp",900);
        setup();
}

void die()
{
        object winner,ob,obj;
        int j;

        ob = this_object();
        obj = new(__DIR__"big-snake");
        winner = ob->query_temp("last_damage_from");
        j = random(50)+50;

        if(!winner)
                ::die();
        if( random(100) < 30 && winner->query_temp("area/k-snake") < 12)
        {
                message_vision("$N猛然的咬住$n，毒牙內的毒液緩緩流入$n的體內．．．\n",ob,winner);
                tell_object(winner,"你覺得體內真氣流失了一部分．．．\n");
                winner->add("combat_exp",-j);
                winner->add_temp("area/k-snake",1);
        }
        else if (winner->query_temp("area/k-snake") >= 12 )
        {
                winner->delete_temp("area/k-snake");
                message_vision("[沙～沙～]一股響亮磨擦聲陣陣接近．．\n",ob);
                obj->move(environment(winner));
                obj->kill_ob(winner);
        }
        ::die();
}
