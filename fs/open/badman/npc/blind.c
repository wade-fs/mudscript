#include "/open/open.h"
#include <ansi.h>

inherit NPC;

void greeting(object me);

void create()
{
      set_name("盲眼人",({"blind person","blind","person"}) );
      set("long",@LONG
一個兩眼失明的人，好像遺失了什麼東西，正茫然的站在街頭，似乎等待著
你的協助(help)。
LONG
      );
      set("age",40);
      set("gender","男性");
      set("attitude","friendly");

      set_skill("dodge",20);
      set_skill("unarmed",10);
      set_skill("parry",20);
      set("combat_exp",300);

      set("chat_chance",1);
      set("chat_msg",({
          "盲眼人滿身大汗的蹲在地上摸索，似乎在找尋什麼。\n",
          "盲眼人喃喃自語的說道：糟了、糟了，要怎麼辦才好？\n",
      }) );

      set("inquiry",([
          "協助" : "你...你能幫我找回我的拐杖嗎?\n",
          "help" : "我的拐杖弄丟了，你能幫我找嗎？\n",
          "拐杖" : "我剛剛不知和誰相撞，這一撞、拐杖便不見了。\n",
      ]) );

      setup();

      carry_object("/obj/cloth")->wear();
      add_money("coin",20);
}

void init()
{
      object me;
      ::init();
      if( interactive( me=this_player() ) && !is_fighting() ) {
            remove_call_out("greeting");
            call_out("greeting",1,me);
      }
}

void greeting(object me)
{
      if( !me||environment(me)!=environment() ) return;
      else
      say ("盲眼人問道：呃...閣下是否能幫小弟一個忙？\n");
}

int accept_object(object me,object ob)
{
      object mask;
      me=this_player();
      if( ob->query("id")=="crutch" ) {
            tell_object(me,
            "盲人喜道：啊！是我的拐杖沒錯，多謝大俠、多謝。小弟無以回報...\n");
            message_vision("盲眼人伸手到懷裡摸了摸。\n", me);
            tell_object(me,
            "盲人喜道：嗯...有了，大俠、這是我的一點心意，你就收下吧！\n");
            message_vision("盲眼人拿出了一件物事，交到了$N的手中。\n",me);
            mask = new(BAD_OBJ"mask");
            mask -> move(me);
            tell_object(me,
            "盲人說道：反正這東西我也用不到，就送給您好了。我先走了，大俠、告辭。\n");
            destruct(this_object());
            return 1;
      }
      else
      return notify_fail("盲人苦笑道：閣下就別和我開玩笑了吧！\n");
}
