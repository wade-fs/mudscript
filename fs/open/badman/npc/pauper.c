#include "/open/open.h"
#include <ansi.h>

inherit NPC;

void create()
{
      set_name("乞丐",({"pauper"}) );
      set("long",@LONG
一個衣衫襤褸的乞丐，沿街在向人乞討著。年紀似乎便只有卅出頭，手上卻拿著一隻
拐杖(crutch)；你突然心念一動，莫非...
LONG
      );
      set("age",32);
      set("attitude","friendly");
      set("gender","男性");

      set_skill("unarmed",30);
      set_skill("dodge",30);
      set_skill("parry",30);
      set("combat_exp",450);

      set("inquiry",([
          "拐杖" : "你不給我錢便罷了，你問這幹嘛？\n",
          "crutch" : "你這麼喜歡啊？一兩黃金，不要拉倒。\n",
          "盲眼人" : "你...我不知道你在問啥啦！\n",
      ]) );

      set("chat_chance",2);
      set("chat_msg",({
          (:random_move:),
          "乞丐拉了拉你的衣角，向你乞討。\n",
          "乞丐說道：好心的老爺啊．．\n",
      }) );

      setup();

      carry_object("/obj/cloth")->wear();
}

int accept_object(object me,object ob)
{
      object crutch;
      me=this_player();
      if( ob->value()>=10000 ) {
            tell_object(me,"乞丐喜道：哈！這麼多錢，要十隻拐杖也給你了。\n");
            message_vision("乞丐拿給$N一根拐杖。\n",me);
            crutch = new(BAD_OBJ"crutch");
            crutch -> move(me);
            tell_object(me,"乞丐得意的說：下次想買拐杖時，記得找我啊。哈！\n");
            return 1;
      }
      else
      return notify_fail("乞丐嫌道：喂！拜託，這點錢哪夠啊？有誠意點嘛！\n");
}
