#include <ansi.h>
inherit NPC;
 
void create()
{
      set("title","晚月莊第二代舞者");
      set_name("水靈兒",({"linr"}) );
      set("gender","女性");
      set("age",20);
      set("attitude","friendly");
      set("class","dancer");
      set_skill("unarmed",100);
      set_skill("dodge",100);
      set("combat_exp",9999990);
 
      set("chat_chance",1);
 
      set("inquiry",([
           "明月" : "就是這次我找他簽名的這個巫師啊!!\n",
           "tide" : "tide=明月，do you know...?\n",
           "FS"   : "這你都不知道，那你現在是在玩哪個MUD呢??\n",
           "ode"  : "就是明月的師父啊!!明月的本事都是他教的呢!!\n",
           "wade" : "FS的天神啊!!聽說明月蠻崇拜他的耶!!\n",
       ]));
 
      setup();
 
      carry_object("/obj/cloth")->wear();
}
 
void init()
{
      object me;
      ::init();
      if( interactive( me=this_player()) && !is_fighting() ) {
        if( me->query("id")=="lum" ) {
          write ("周會敏喜道：哇！明月來了！簽名、簽名。\n");
        }
        if( me->query("id")=="lopo" ) {
          write ("周會敏感激道：哇！是風靈耶....謝謝你那麼幫明月。謝謝！\n");
          command("kiss "+me->query("id"));
        }
        if( me->query("id")=="oda" ) {
          write ("周會敏驚道：你...你不是tide的師父？久仰、久仰...\n");
          message_vision(HIC"周會敏盈盈的向$N磕了個頭，說道：我代tide謝謝你。\n"NOR,me);
          command("thank "+me->query("id"));
        }
        remove_call_out("greeting");                                                 remove_call_out("greeting");
        call_out("greeting",2,me);
      }
}
 
void greeting(object me)
{
      if( !me||environment(me)!=environment() ) return;
      switch ( random(3) ) {
      case 0:
      write("周會敏問道：你也是來找明月簽名的嗎？還是有啥事。\n");break;
      case 1:
      write("周會敏說道：我先來的喔，待會兒明月來時，我是第一讓他簽名的喔。\n");
      break;
      case 2:
      write("周會敏喜道：啊！我認識你，你也是FS的巫師嘛。簽名、簽名！\n");
      break;
      }
}
