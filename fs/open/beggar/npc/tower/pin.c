inherit NPC;
#include <ansi.h>
void create()
{
        set_name("方平",({"pin"}));
        set("long","我叫方平\n");
        set("gender","男性");
        set("class","beggar");
        set("nickname",HIW"德國總裁！"NOR);
        set("combat_exp",10000000);
        set("attitude","friendly");
        set("age",30);
        set("str", 40);
        set("cor", 40);
        set("cps", 30);
        set("per", 35);
        set("spi", 40);
        set("int", 20);
        set("con", 30);
        set("kar", 30);
        set("max_gin", 50000);
        set("max_kee",50000);
        set("max_sen", 50000);
        set("max_force",50000);
        set("force",50000);
        set("max_atman",10000);
        set("max_mana",10000);
        set("mana",10000);
        set("atman",10000); 
        set_skill("staff",130);
        set_skill("pkdog-staff",120);
        map_skill("staff","pkdog-staff");
        set_skill("force",100);
        set_skill("pkdog-force",120);
        map_skill("force","pkdog-force");
        set_skill("dodge",110);
        set_skill("move",100);
        set("force_factor",20);
        set_skill("unarmed",90);
        set_skill("parry",90);
        set_skill("beggar-steps",100);
        map_skill("dodge","beggar-steps");
        map_skill("move","beggar-steps");
        set("bellicosity",10000);
        set("beggar/got_secret",1);
        set("beggar/got_dogup",1);
        set("beggar/got_phoenix",1);
        set("MKS",40000);
        set("chat_chance",2);
        set("functions/skydog/level",100);
        set("functions/dogup/level",100);
        set("functions/dog-phoenix/level",100);
        set("functions/dog-tiger/level",100);
        set("functions/dog-dragon/level",100);
        setup();
        carry_object("/open/beggar/obj/cloudstaff")->wield();
}



int accept_kill (object who)
{
  this_object()->delete_busy();
  command ("say 看我的ｓｌｉｍｂｏｄｙ！"); 
  command ("wield staff");
  command ("wear all");
  command ("exert dog-phoenix");
  command ("exert dog-tiger");
  command ("exert dog-dragon");
  command ("exert dog-shanwu");
  return 1;
}

int accept_fight (object who)
{
  this_object()->delete_busy();
  command("ohoh");
  command ("say 你閃開！"); 
  command ("wear all");
  command ("exert dog-phoenix");
  command ("exert dog-tiger");
  command ("exert dog-dragon");
  command ("exert dog-shanwu");
  return 0;
}


void heart_beat()
{
        if( !is_fighting() ) {
                if( query("force") < query("max_force") ) // 1 -> 5.035
                        command( "ex 160" );
                if( query("eff_kee") < query("max_kee") ) // 35
                        command( "10 exert heal" );
                if( query("gin") < query("eff_gin") ) // 125
                        command( "exert regenerate" );
                if( query("kee") < query("eff_kee") ) // 125 -> 300
                        command( "3 exert recover" );
                if( query("sen") < query("eff_gin") ) // 125
                        command( "exert refresh" );
        }
                if ( this_object()->is_fighting() && random(50)>25)
                {
                        message_vision(HIM"$N不甘心被壓著打，一聲怒吼，解開了被封穴道！\n"NOR,this_object());
                        this_object()->delete_busy();
                }

        ::heart_beat();
}

void die()
{
    object winner,ob;
    if( winner = query_temp("last_damage_from") )
    tell_object(winner,"你從方平身上割下一粒人頭。\n");
    ob=new("/open/beggar/obj/pin-head");
    ob->move(winner);
    winner->set_temp("ko_pin",1);
    environment(winner)->delete_temp("block");
    destruct(present("cloud staff",this_object()));
        tell_object(users(),HIC"
                方平死前竭盡地吶喊著！
                　　
                　玉珊～～

                　　　"HIY"爸爸先走一步了．．．．

                　　　　　　"HIW"你要好好替爸爸弄好"HIC"ｓｌｉｍｂｏｄｙ"HIW"～～\n"NOR);

    destruct(this_object());
 :: die();
}

