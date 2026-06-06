#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
int do_list();
int do_trade(string);
void create() {
set("short",CYN"馬匹集散中心"NOR);
	set( "build", 12 );
set("long",@LONG

這裡是全國最大的馬匹銷售中心。你可以在這裡找到你所需要的馬
來與您並肩作戰，從這裡向裡望去，只見一整排的馬廄，而裡面所
飼養的馬都是當今最珍貴的馬種。你可以使用(view)查看這裡有賣
哪些好馬。

LONG);
        set("exits",([ /* sizeof() == 1 */
            "west" : "/open/port/room/r2-2",
      ]));
        set("light_up", 1);
        set("no_kill", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
}

void init() {
  add_action("do_list","view");
        add_action("do_trade","trade");
}

int do_list() {
        return notify_fail("

            小店所販賣的馬匹如下:

       幽靈魍馬 (urain horse)       exp :  900000        :  100 金
       黑夜奔雷 (Dark horse)        exp :  700000        :   90 金
       赤兔馬   (Red horse)         exp :  550000        :   80 金
       烏黑駒   (Black horse)       exp :  450000        :   70 金
       龍驤馬   (Dragon horse)      exp :  350000        :   60 金
       騏驎駒   (Jeelin horse)      exp :  250000        :   50 金
       騊駼駒   (Tau horse)         exp :  150000        :   40 金
       驒騱\駒   (Twosee horse)      exp :   80000        :   30 金
       驊騮駒   (Whaliu horse)      exp :   30000        :   20 金
       驌驦駒   (Sueswan horse)     exp :       0        :   10 金

           您只需下 trade <名稱> 即可採購，謝謝您的光臨！\n\n");
}

int do_trade(string str) {
        int gold,silver,exp,i,money;
        object me,horse;
        me = this_player();
        if(me->query_temp("have_horse"))
 return notify_fail(HIY"董老闆說道：一個人只能買一匹馬喔。\n"NOR);
        switch(str) {
           case "urain horse"    :
                horse = new("/open/gblade/npc/horse/urain");
                break;
           case "dark horse"    :
                horse = new("/open/gblade/npc/horse/dark");
                break;
           case "tyna horse"    :
                horse = new("/open/gblade/npc/horse/tyna");
                break;
           case "red horse"     :
              horse = new("/open/gblade/npc/horse/red");
              break;
           case "black horse"   :
              horse = new("/open/gblade/npc/horse/black");
              break;
           case "dragon horse"  :
              horse = new("/open/gblade/npc/horse/dragon");
              break;
           case "jeelin horse"  :
              horse = new("/open/gblade/npc/horse/jeelin");
              break;
           case "tau horse"     :
              horse = new("/open/gblade/npc/horse/tau");
              break;
           case "twosee horse"  :
              horse = new("/open/gblade/npc/horse/twosee");
              break;
           case "whaliu horse"  :
              horse = new("/open/gblade/npc/horse/whaliu");
              break;
           case "sueswan horse" :
              horse = new("/open/gblade/npc/horse/sueswan");
              break;
default : return notify_fail(HIY
"董老闆說道：抱歉！本店並不售這種東西！\n"NOR);
        }
        exp = (int)horse->query("exp");
        gold = (int)horse->query("gold");
        silver = (int)horse->query("silver");
        money = gold*10000 + silver*100;
        if(me->query("combat_exp") < exp)
return notify_fail(HIY
"董老闆說道：你恐怕無法駕馭此馬，請另選一匹吧！\n"NOR);
        if(!me->pay_money(money))
return notify_fail(HIY
"董老闆說道：你的錢不夠，我的馬匹無法賣給你！\n"NOR);
	me = this_player();
        horse->move(environment(me));
        horse->set_leader(me);
        horse->set("family/family_name",me->query("family/family_name"));
        horse->set_temp("my_boss",(string)me->query("id"));
        me->set_temp("horse",(string)horse->query("id"));
        me->set_temp("have_horse", 1);
        message_vision(HIC"$N買下了一匹馬！\n"NOR,me);
return notify_fail(HIY
"董老闆說道：謝謝您的惠顧！請下次再來！\n"NOR);
}

