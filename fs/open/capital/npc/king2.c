#include <ansi.h>

inherit NPC;
string ask_moon();
int accept_kill(object who);
void create()
{
        set_name(HIM "天子" NOR, ({ "king" }) );
        set("title","當今皇上");
        set("gender", "男性" );
        set("age",50);
        set("str",50);
        set("cor",45);
        set("cps",35);
        set("int",50);
        set("long",
            "一位高大英挺的男人，言行舉止中有著令人無法抗拒的威嚴。\n"
            "但似乎有些事困擾著他，因而顯的有點鬱鬱寡歡。\n");
        set("class","fighter");
        set("clan_kill",1);
        set("del_delay",1);
        set("no_hole",1);
        set("no_plan",1);
         set("no_plan_follow",1);

          set("capital_king",1);
        set("combat_exp",15500000);
        set("attitude", "heroism");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
            (: exert_function, "recover" :)
            }) );
     set_skill("dodge",250);
         set_skill("unarmed",250);
      set_skill("kingfist",250);
        set_skill("parry",250);

      set_skill("force",250);
      set_skill("fireforce",250);
      set_skill("bss-parry",250);
      set_skill("bss-steps",250);
        map_skill("force","fireforce");
        map_skill("unarmed","kingfist");
        map_skill("dodge","bss-steps");
        map_skill("parry","bss-parry");
          set("force",150000);
         set("max_force",100000);
          set("force_factor",40);
        set("max_gin",30000);
        set("gin",30000);
        set("max_kee",30000);
        set("kee",30000);
        set("max_sen",30000);
        set("sen",30000);
        set("chat_chance", 15);
        set("chat_msg", ({
              "天子說: 朕最近心情很差。\n",
              "天子說: 後宮佳麗三千，各各爭寵，叫朕怎忙得過來。\n",
             "天子說: 真該去練練帝王神功\了。\n",
        }) );
                set("inquiry",([
            "月半彎"  :  (:ask_moon:)
        ]));
        setup();
          carry_object("/open/capital/obj/king-belt")->wear();
carry_object("/open/capital/obj/secret_book");
          carry_object("/open/capital/obj/king-boots")->wear();
          carry_object("/open/capital/obj/king-cloak")->wear();
          carry_object("/open/capital/obj/king-cloth")->wear();
          carry_object("/open/capital/obj/king-ring")->wield();
          carry_object("/open/capital/guard/gring")->wear();
          add_money("gold",1000);

}

void init()
{
         object me=this_player();
         int force,be;

         be=me->query("bellicosity");
         force=me->query("force");
         if(be > force)
         {
         kill_ob(me);
         accept_kill(me);
         }

        add_action("do_fight", "fight");
        add_action("do_fight", "kill");
        add_action("do_cmd","cmd");
}
int do_cmd(string str) {
 object who=this_player();
 if(str=="askgod king" || str=="askgod guard" || str=="askgod king guard") {
 who->start_busy(2);
 kill_ob(who);
 accept_kill(who);
}
 else if(str=="vet king" || str=="vet guard" || str=="vet king guard") {
 who->start_busy(2);
 kill_ob(who);
 accept_kill(who);
}
else if(str=="bak king" || str=="bak guard" || str=="askgod king guard") {
  who->start_busy(2);
  kill_ob(who);
  accept_kill(who);
} else if(str=="cmd throw king"  || str=="cmd throw guard"  || str=="cmd throw gua
rd"){
 who->start_busy(2);

 kill_ob(who);
 accept_kill(who);
}
 return 1;
}
string ask_moon()
{   object who;
    who = this_player();
    if(!this_player()->query_temp("ask_moon2"))
        return "嗯....這我可不清楚﹐你最好問問別人吧。";
         command("say 你知道她在哪嗎??快告訴我!!!");
         command("say 你怎麼會知道這件事 ?");
         this_player()->set_temp("ask_moon3",1);
         kill_ob(who);
     accept_kill(who);
}
int do_fight(string arg)
{
        object who;
        who = this_player();

          if (!arg || arg!="king")
                return notify_fail("你想攻擊誰﹖\n");
        else {
                kill_ob(who);
                accept_kill(who);
        }

        return 1;
}

int accept_kill(object who)
{
         object ob, guard;
        ob = this_object();

        if( !present("kill guard", environment(ob)) ) {
          if (ob->query_temp("killking")!=1){
          tell_room(environment(ob),HIW"\n突然！衝出兩位御前侍衛長！\n\n"NOR);
        guard = new(__DIR__"fuguard");
        guard->move(environment(ob));
        guard->command("defend king");
        guard->command("follow king");
        guard->kill_ob(who);
        guard = new(__DIR__"fuguard1");
        guard->move(environment(ob));
        ob->set_temp("killking",1);      
        guard->command("follow king");
        guard->kill_ob(who);
        tell_object(users(),HIR "御前護衛大叫：有刺客！快保護殿下！！\n" NOR);
        command("wear all");

}
         else {
              command("say 可惡  ...看我的帝王神功\..");
              tell_object(this_player(),HIC"只覺無比厚重的壓力硬往你身上壓來\n"NOR
);
              this_player()->add("kee",-(this_player()->query("max_kee")/2));
    }

}
        return 1;
}
void heart_beat()
{
        object me=this_object();
          if(me->is_fighting()){
         if(50 > random(100))
           {
        me->delete_busy();
        message_vision("$N舒展了一下筋骨，瞬間生龍活虎了起來!!!\n",me);
         }
         }
        ::heart_beat();
}
 void die()
 {    object ob;
     int i,j;
         object winner = query_temp("last_damage_from");
     winner->set("secret_book",1);
         if(this_player()->query_temp("ask_moon3")==1)
         { command("say 自從她離開後我多次派人尋訪不著,也許\李逍遙知道她的下落吧");
        command("say 如果你找到她幫我把這封信交給她"); 
        new("/open/capital/obj/letter")->move(this_player());
        message_vision("皇上給了$N一封信 .\n",ob);
        this_player()->set_temp("ask_moon4",1);
                }
                
 

          tell_object(users(),HIR"\n\n

   『啊～～～～～～ 』

    一聲慘叫從皇城中傳出, 劃破了天際, 震撼了每個人的心


      『皇上駕崩啦～～～～』．．．．．．

    百姓紛紛面朝皇城的方向跪地磕頭, 有些人甚至哭了起來

      太后大叫道: 可惡的"+((winner&&objectp(winner)==1)?winner->query("name"):"咕哩貓")+HIR", 竟敢以下犯上,

                凡我同胞, 人人得而誅之!!!!!
  \n\n"NOR);
  if( winner != 0 && userp(winner)) {
    log_file("KILL_KING", sprintf("%s(%s) 打敗 天子 on %s\n",winner->query("name"),winner->query("id"), ctime(time()) ));
  }

    :: die();
 }

