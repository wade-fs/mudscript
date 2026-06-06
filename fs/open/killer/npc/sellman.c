//vendor.c
#include "/open/open.h"
inherit F_VENDOR;

void create()
{
set_name("殺手專賣處的老闆",({"vendor"}));
set("gender", "男性" );
set("age", 50);
set("long", @LONG
他可是葉秀殺特地請來的退休殺手，你可不要想殺他哦。。。。
,你可以列出(list)他賣些什麼...
LONG
);
        set("combat_exp",200000);
        set("max_kee",2000);
        set("kee",2000);
        set("attitude", "friendly");
        set_skill("dodge", 80);
        set_skill("hammer", 80);
        set_skill("parry", 80);
        set("vendor_goods", ({
                COMMON_OBJ"bandage",
                COMMON_OBJ"pill",
                COMMON_OBJ"pill1",
                COMMON_OBJ"plaster",
                PING_OBJ"cloud",
                CAPITAL_OBJ"tea",
                "/obj/example/wineskin",
                "/obj/example/dumpling",
                "/obj/example/chicken_leg",
}) );
setup();
        carry_object("/obj/example/chicken_leg")->wield();
        carry_object("/open/killer/weapon/k_cloth2")->wear();
add_money("gold",2);
}

void greeting(object ob)
{
int gender,per;
gender = 0;
per = ob->query_per();
if( !ob || environment(ob) != environment() ) return;
if( ob->query("gender") == "女性")
  gender = 1;
switch( random(3) ) {
case 0:
                if( per < 18 && gender)
          say("老闆微笑的說：呵。。。 "+ob->name(1)
                       +",妳還真有勇氣出門嚇人耶!\n");

say("老闆愉快的靠近你說： 這位"+RANK_D->query_respect(ob)
                        +"你是新進殺手吧？來買點東西如何？!\n");
break;
case 1:
                if( per > 22 )
                   say("老闆嘶聲么\喝道: "+ob->name(1)
                        +"奇怪，妳是舞者嗎？沒事那麼漂亮幹嘛？!\n");
                say("老闆嘶聲么\喝道: "+RANK_D->query_respect(ob)
                    +",西域神器喚雲扇!這裡買，價格一樣啦！?\n");
break;
case 2:
                if( per < 15)
say("老闆自言自語的說： "+ob->name(1)+"！？？"
            +"\n還好，我還以為，我家養的猴子跑出來了！！\n");
if( per > 26 && gender)
                    say("老闆讚嘆道: 哇! 惡魔"+ob->name(1)
        +",妳真是令人不禁想要犯罪耶。。。。!!\n");
        
say("老闆高聲喊道: 跳樓大拍賣,"+RANK_D->query_respect(ob)
+"當我老婆的話，我可以算便宜一點喔!\n");
break;
 }
}
