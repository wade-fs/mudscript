// /open/center/npc/vendor.c
#include "/open/open.h"

inherit F_VENDOR;

void create()
{
	set_name("王鐵匠", ({ "wang" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long", @LONG
他是蜀中鐵鋪的老闆,你可以問問他有在賣甚麼(list).
LONG);
	set("attitude", "friendly");
	set("combat_exp",163);
	set_skill("dodge",20);
	set("vendor_goods", ({
            GS_OBJ"woodsword",
	    GS_OBJ"sword",
            GS_OBJ"woodblade",
	    "/obj/example/dagger",
	    "/open/gblade/obj/blade",
            "/open/ping/obj/fan-2",
	    "/open/poison/obj/longwhip",
	    "/open/gblade/obj/pen",
	}) );

	set("greeting_msg", ({
 	    "王鐵匠說: 來ㄡ!! 來ㄡ!! 快來快買,晚來晚買!!\n",
	    "王鐵匠喊道: 王鐵匠武器超值大拍賣!! \n",
        "王鐵匠叫道: 先生小姐,買把武器防身吧!! 當色狼,打色狼,都很實用喔!!\n",
	}) );
	setup();
        carry_object("/open/gsword/obj/dirty_cloth")->wear();
	carry_object("/obj/example/dagger")->wield();
}
void check_zombie(object obj)
{
  if(obj && obj->query_temp("control") == 6) 
  {
    if(!present("zombie",environment(this_object())))
    {
      command("say 你把我爸帶去哪裡了？！！！！");
      command("sob");
    } else {
      command("say 爸!!!!!!");
      command("say 終於可以把父親安心下葬了!!!");
      obj->set_temp("control", 7);
      destruct(present("zombie",environment(this_object())));
    }
  }

}
void init()
{
  object obj; 
  obj = previous_object();

  ::init();
  call_out("check_zombie",1,obj);
}
