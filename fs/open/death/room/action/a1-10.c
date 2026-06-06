// 背景效果

inherit NPC;

void create()
{
          set_name(" ",({"action"}));
          set("short","");
          set("chat_chance",5);
          set("chat_msg",({
          "你看到這裡來來往往的遊魂很多，但能往第二殿的卻是少數。\n",
          "關卡守衛踹了踹一隻窮苦的老鬼說：「沒錢免談！」\n",
          "關卡守衛抖了抖身上的金鍊子，臉上滿是得意的笑容。\n"
	}) );
	setup();
}
