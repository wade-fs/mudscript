#include <ansi.h>
string ask_dogup()
{
        object me=this_player();
        if(me->query("class") != "beggar")
        return "問什麼問？快走開！";
        if(me->query("combat_exp") <1500000 
          || me->query_skill("pkdog-force",1) <150)
        return "你能力不夠問了也是白問！\n";
        else{
        command("say 犬化四象呀．．那是丐幫獨特的上乘心法。");
        command("say 至今已經很少人會了，若你能幫我取得我心儀之物，我就將它教授與你。");
        me->set_temp("ask_dogup",1);}
}

inherit NPC;
void create()
{
        set_name("神秘長老", ({ "mysterious leader","leader" }) );
        set("long", "\n");
        set("race","人類");
        set("age", 60);
        set("max_gin", 1000);
        set("max_kee", 5000);
        set("max_sen", 1000);
        set("combat_exp",50000);
        set("no_kill",1);
        set("inquiry",([
            "心儀之物" : "我想要的東西就是洗髓丹、獨孤嵊的人頭、以及生生造化丹。\n",
            "犬化四象" : (: ask_dogup :),
                     ]));
        setup();
        add_money("coin", 1);
}


int accept_object(object me, object obj)
{
   string obj_name= obj->query("name");
   if( me->query_temp("ask_dogup"))
   {
      if( obj_name == HIR"獨孤嵊的人頭"NOR)
      {
                 if(this_player()->query_temp("ko_sa")==1)
                 {
         command("pat "+getuid(me));
         command("say 太好了, 這是"+ obj_name+ "");
         me->set_temp("head_ok", 1);
         destruct(obj);}else{
                 command("say 這不是你親手打的，沒收!!");
                 destruct(obj);}
      }
          if ( obj_name == HIR"生生造化丹"NOR)
          {
         command("spank "+getuid(me));
         command("say 太好了, 這是"+ obj_name+ "");
         me->set_temp("pill_ok", 1);
         destruct(obj);
          }
          if ( obj_name == YEL"洗髓丹"NOR)
          {
         command("spank "+getuid(me));
         command("say 太好了, 這是"+ obj_name+ "");
         me->set_temp("dan_ok", 1);
         destruct(obj);
          }
         if( me->query_skill("pkdog-force",1) <100 
             || me->query("combat_exp") < 1500000)
         {
            command("say 唔，你的能力(心法或經驗)仍嫌不足，你再去努力吧！");
            return 1;
         }

         if( me->query_temp("head_ok")==1
             &&me->query_temp("pill_ok")==1
             &&me->query_temp("dan_ok")==1
             &&me->query_skill("pkdog-force",1)>100
             &&me->query("combat_exp")>1500000)
         {
            command("say 不錯，即然你幫我取到了我想要的東西，你果然有資格習得本幫上乘心法！");
                        tell_object(users(),me->query("name")+HIC"已習得本幫上乘心法，希望以後替丐幫行俠仗義
                                \n\t\t\n"HIW"哇～哈～哈～～\n"NOR);
                        me->set("beggar/got_dogup",1);
                        me->set("title",HIC"丐幫"HIW"《"HIR"四獸武學"HIW"》"NOR);
            return 1;
         }
      }

   else
   {
      command("stare "+getuid(me));
          command("eh "+getuid(me));
      command("say 給我這種東西幹麻...");
      obj->move( me);
      message_vision("神秘長老將"+ obj->query("name")+ "還給了$N。\n", me);
      return 1;
   }
}


