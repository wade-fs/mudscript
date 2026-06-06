// snow.c
#include <ansi.h>

inherit NPC;

void die()
{
    object killer;
    
     if(!query_temp("last_damage_from"))return ::die();
     else
      {
        killer=query_temp("last_damage_from");
        if( killer && present("letter",killer) ) killer->set("quests/kill-snow",1);
      }
       return ::die();
}

int do_move( object me )
{
        remove_call_out("do_move");
        load_object("/open/snow/room/help_room");
        me->move("/open/snow/room/help_room");
}

int do_revive( object me )
{
        remove_call_out("do_revive");
        me->revive();
}

int fight_end( object me )
{
        remove_call_out("fight_end");
        if( !me ) return 0;
    if(me->is_ghost()) return 1;
        if( me->query_temp("no_fear_poison") ) return 0;
        message_vision(HIY "$N突然地感到一陣暈炫 .... " NOR,me);
        message_vision("\n",me);
        tell_object( me , HIC "你的怨世寒毒發作了﹗\n" NOR);
        this_object()->remove_all_killer();
        me->unconcious();
        call_out("do_move",4,me);
        call_out("do_revive",5,me);
}

int start_fight( object me )
{
        remove_call_out("start_fight");
        if( !me ) return 0;
        command("say 你不是聖賢書 ?");
        command("say 哦 ? 你是代他而來 ? 好吧 ! 一樣受死吧 !\n");
        this_object()->kill_ob(me);
}

void create()
{
        set_name("雪魂",({"snow"}));
        set("title","幻影娘子");
        set("gender","女性");
        set("age", 26);
        set("combat_exp", 500000 );
        set("max_kee",1500);
        set("kee",1500);
        set("force",2000);
        set("max_force",2000);
        set("force_factor",20);
        set_skill("unarmed",300);
        set_skill("dodge",300);
        set_temp("apply/damage",60);
        set_temp("apply/armor",40);

        set("str",30);
        setup();
}

void init()
{
        object me = this_player();
        object ob;
        if( (ob = present("letter",me)) && ob->name()==HIR"挑戰書"NOR )
        {
                call_out("start_fight",2,me);
                call_out("fight_end",30,me);
        }
}

int accept_fight( object who )
{
        command("say 我現在必須保持體力﹐恕我不能奉培。");
        return 0;
}

int accept_kill( object who )
{
        command("say 憑你 ....");
        command("laugh");
        return 0;
}
