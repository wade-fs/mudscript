#include <ansi.h>
inherit F_VENDOR;

string magic1();

void create()
{
        set_name("土地公",({"ground god", "god"}));
        set("long","最近廟裡香火不盛, 土地公為了生活, 所以兼點副業, 賣賣金紙跟香火。\n");
        set("gender","男性");
        set("combat_exp",100000);
        set("attitude","heroism");
        set("age",200);
        set("str", 99);
        set("cor", 99);
        set("cps", 99);
        set("per", 99);
        set("spi", 99);
        set("int", 99);
        set("force",5000);
        set("max_kee",5500);
        set("kee",5500);
        set("max_gin",5500);
        set("gin",5500);
        set("max_sen",5500);
        set("sen",5500);
        set("max_force",5000);
        set("max_mana",5000);
        set("mana",5000);
        set("max_atman",5000);
        set("atman",5000);
        set("force_factor",20);
        set_skill("literate",100);
        set_skill("move",100);
        set_skill("force",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("whip",100);
        set_skill("parry",100);

        set_skill("gwhip",100);
        set_skill("gforce",100);
        set_skill("g-steps",100);

        map_skill("whip","gwhip");
        map_skill("force","gforce");
        map_skill("dodge","g-steps");
        set("vendor_goods",({
                "/open/killer/mon/ghost/obj/gpaper.c",
                "/open/killer/mon/ghost/obj/incense.c",
        }) );   
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
        (: magic1 :),
        }));
        setup();
        carry_object("/open/tendo/obj/goldwhisk")->wield();
        carry_object("/open/tendo/obj/hat")->wear();
        carry_object("/open/tendo/obj/robe")->wear();
        carry_object("/open/tendo/obj/shoe")->wear();
}

void init ()
{
  ::init ();
  set ("class", "taoist");
}

int accept_fight( object me)
{
   command("say 你看清楚, 我是土地公耶, 土地公你也敢打....");
   return 0;
}

int accepy_kill( object me)
{
   if( me->query("combat_exp") < 1000000)
   {
      command("say 哇靠...我是土地公耶, 是神耶, 你竟然要殺我...");
      command("say 不過我佛慈悲, 我不會跟你一般計較的, 你走吧...");
      return 0;
   }
   command("say 哇靠...我是土地公耶, 是神耶, 你竟然要殺我...");
   command("say 既然是這樣, 那我就不能輕易饒了你。");
   message_vision("只見土地公口中念念有詞:「南無ㄚ嘧哄, 風火雷電冰...」\n", me);
   message_vision("瞬間土地公的身形突然長大數倍, 全身青筋爆起, 周身纏繞著騰騰雲霧\n", me);
   message_vision("隨即大喝一聲, 拂塵電閃而至...\n", me);
   set("combat_exp", me->query("combat_exp")*0.5);
   return 1;
}

string magic1()
{
        command("cast feeblebolt");
        return "\n";
}
