// /open/center/npc/vendor.c
//先期堆出，以後在改賣東西
#include "/open/open.h"

inherit F_VENDOR;

void create()
{
set_name("李大牛", ({ "lee" }) );
set("gender", "男性" );
set("age", 42);
set("long", @LONG
他是殺手總壇的專賣員,是葉秀殺的好意為殺手們特別引進的，賣甚麼可用(list)知道
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
     "來ㄡ!! 來ㄡ!! 快來快買,晚來晚買!!\n",
    "武器超值大拍賣!! \n",
        "先生小姐,買把武器防身吧!! 當色狼,打色狼,都很實用喔!!\n",
}) );
setup();
        carry_object("/open/gsword/obj/dirty_cloth")->wear();
carry_object("/obj/example/dagger")->wield();
}
