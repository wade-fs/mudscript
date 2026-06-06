
#include <ansi.h>

inherit NPC;
int accept_kill(object who);
void create()
{
        set_name( "皇太后" , ({ "king-mother" }) );
        set("title","母儀天下");
        set("gender", "女性" );
        set("age",70);
        set("str",50);
        set("cor",45);
        set("cps",35);
        set("int",50);
        set("long",
            "她就是當今皇上的娘，也就是皇太后，你瞧見她那在不經意中流\n"
            "露的威嚴，使你不敢太靠近她。\n");
        set("combat_exp",7000000);
        set("attitude", "heroism");
        set("chat_chance_combat", 60);

        set("chat_msg_combat", ({
            (: exert_function, "recover" :)
            }) );
        set_skill("dodge",200);
        set_skill("dagger",200);
        set_skill("fly-circle",200);
        set_skill("parry",200);
        set_skill("force",200);
        set_skill("fireforce",200);
        set_skill("bss-parry",200);
        set_skill("bss-steps",200);
        map_skill("force","fireforce");
        map_skill("dagger","fly-circle");
        map_skill("dodge","bss-steps");
        map_skill("parry","bss-parry");
         set("force",5000);
         set("max_force",5000);
         set("force_factor",10);
        set("kee",10000);
        set("max_sen",3000);
        set("max_gin",3000);
        set("gin",3000);
        set("sen",3000);
        set("chat_chance", 15);
        set("chat_msg", ({
              "太后說: 最近天氣真熱阿。\n",
              "太后說: 我最討厭動刀動槍了。\n",
              "太后說: 皇兒真是個孝順的孩子。\n",
        }) );
        setup();
        carry_object("/open/capital/room/king/obj/dagger1")->wield();
        add_money("gold",25);

}

void init()
{
        add_action("do_fight", "fight");
        add_action("do_fight", "kill");
        add_action("do_cmd", "cmd");

}
int do_cmd(string str) {
 object who=this_player();
 if(str=="askgod king" || str=="askgod guard" || str=="askgod king guard") {
 who->start_busy(1);
 kill_ob(who);
 accept_kill(who);
} else if(str=="bak king" || str=="bak guard" || str=="askgod king guard") 
{
  who->start_busy(1);
  kill_ob(who);
  accept_kill(who);
} else if(str=="throw mother"  || str=="throw guard"  || str=="throw guard"){
 who->start_busy(1);
 kill_ob(who);
 accept_kill(who);
}
 return 1;
}


int do_fight(string arg)
{
        object who;
        who = this_player();

        if( !arg || (arg!="guard" && arg!="king") )
                return notify_fail("你想攻擊誰﹖\n");
        else {
                kill_ob(who);
                accept_kill(who);
                who->start_busy(2);
        }

        return 1;
}

int accept_kill(object who)
{
        int i;

        object ob, guard;
        ob = this_object();

        if( !present("king guard", environment(ob)) ) {
          if (ob->query_temp("killking")!=1){
         tell_room(environment(ob),HIW"\n突然！衝出兩位御前護衛！\n\n"NOR);
      for(i=0;i<2;i++)
      ob->start_busy(2);
      for(i=0;i<2;i++)
     {
        guard = new(__DIR__"fuguard");
        guard->move(environment(ob));
        guard->command("defend king-mother");
        guard->command("follow king-mother");
        guard->kill_ob(who);
       }
           ob->set_temp("killking",1);
      tell_object(users(),HIR "御前護衛大叫：有刺客！快保護太后！！\n" NOR);
}
else {

              command("say 可惡..逆賊.你還來..找死...");
              tell_object(this_player(),HIC"太后啟動機關..你一時閃避不及慘遭重擊\n"NOR);
              this_player()->receive_wound("kee",(this_player()->query("max_kee")/2));
    }

}
        return 1;
}
 void die()
 { 
     object ob;
     int i,j;
         object winner = query_temp("last_damage_from");
         winner->delete_temp("killking");
  ::die();
}
 



