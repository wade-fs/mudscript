#include <ansi.h>
inherit NPC;

void create()
{
  set_name("牧童", ({ "girl" }) );
  set("gender", "女性");
   set("age", 16);
   set("long",
      "這女孩是專門負責照顧鳳凰的牧童。\n");

  set("combat_exp", 50000);
  set("chat_chance", 5);
  set("chat_msg", ({
     (: command, "say 每天都要照顧這些鳳凰，好累喔。" :),
     (: command, "smrik" :),
}) );

  setup();
}
int accept_fight(object me)
{
  command("sob");
  command("say 這... 你... 我這麼可愛﹐你怎忍心下手呀... 。");
  return 0;
}
int accept_kill(object me)
{
  command("wa");
  command("say 你.....難..道一點....都...不懂..得憐香..惜玉嗎...﹖......");
  return 0;
}
void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;

  command("smile "+ob->query("id"));
  say(HIC + "女孩輕聲說﹕"+ob->name()+HIC + "﹐歡迎來到射手派。\n" + NOR);

}
void init()
{
     object me = this_player();
     if( me->query("Lbird-shop","YES")
|| me->query("family/family_name")=="射日派"
      || wizardp(me) ) {
     add_action("do_list", "list");
     add_action("do_shop", "shop");
     add_action("do_value", "value");
     add_action("do_sell", "sell");
     add_action("do_appraise","appraise");
     } else {
     add_action("no_trade", "list");
     add_action("no_trade", "shop");
     add_action("no_trade", "value");
     add_action("no_trade", "sell");
     add_action("no_trade", "appraise");
     }
}
int do_list(object me)
{
    write("\n\t極燄火鳳凰(fire-phoenix)      - 售價﹕一兩銀子。\n"
          "\t極凍冰鳳凰(ice-phoenix)        - 售價﹕一兩銀子。\n"
          "\t極速風鳳凰(wind-phoenix)       - 售價﹕一兩銀子。\n"
          "\t極殺雷鳳凰(lighting-phoenix)      - 售價﹕一兩銀子。\n"
          "\t極隱闇鳳凰(black-phoenix)      - 售價﹕一兩銀子。\n"
          "\t鑒定(appraise)  看你適合那一個鳳凰            \n\n");
return 1;
}
int do_appraise(object me)
{
me = this_player();
if(me->query("appraise")){
if(me->query("appraise") == 1)
write("你適合極燄火鳳凰。\n");
if(me->query("appraise") == 2)
write("你適合極凍冰鳳凰。\n");
if(me->query("appraise") == 3)
write("你適合極速風鳳凰。\n");
if(me->query("appraise") == 4)
write("你適合極殺雷鳳凰。\n");
if(me->query("appraise") == 5)
write("你適合極隱闇鳳凰。\n");
}else{
write("你都不適合，滾吧。\n");
}
return 1;
}
int do_shop(string str, object me)
{
    int lv;
    object goods;
    me = this_player();
    if( !str ) return notify_fail("[指令格式]﹕buy <id>\n");
    if((me->query("appraise") !=1 && str =="fire-phoenix") ||
       (me->query("appraise") !=2 && str =="ice-phoenix") ||
       (me->query("appraise") !=3 && str =="wind-phoenix") ||
       (me->query("appraise") !=4 && str =="lighting-phoenix") ||
       (me->query("appraise") !=5 && str =="black-phoenix"))return notify_fail("你並不適何這種鳳凰。\n");
    if( str == "fire-phoenix" || str == "ice-phoenix" || str == "wind-phoenix"
            || str == "lighting-phoenix" || str == "black-phoenix" ) {
    if( !me->can_afford(100) ) return notify_fail("你身上沒有足夠的金錢。\n");
    if( file_size("/open/marksman/obj/"+str+".c") < 0
    &&  !find_object("open/marksman/obj/"+str) )
    return command("say 抱歉ㄛ﹐"+me->name()+"﹐這類型的鳳凰似乎缺貨中。\n");
    if( me->query("Lbird") ) {
    write("小女孩說:你已經有一隻鳳凰囉!\n");
    } else {
    write(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 問道" + CYN + "﹕" + HIC
    "你確定要領養一隻新的鳳凰" + CYN + "﹖" + HIW + "(Y/n)" + NOR + "﹕");
    input_to("new_Lbird", me, str);
    return 1;
    }
    } else command("say Sorry﹗"+me->name()+
    "﹐本店沒有這種鳳凰﹐請查閱\(list)鳳凰種類。\n");
    return 1;
}
void new_Lbird(string yn, object me, string str)
{
     object Lbird = new("/open/marksman/obj/"+str);
     if( yn == "" || yn[0] == 'Y' || yn[0] == 'y' ) {
tell_room(environment(me),me->name()+"認養了一隻鳳凰。\n");
     write(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC
     "恭喜你認養了一隻鳳凰" + CYN + "﹐" + HIC + "請好好的照顧它" + CYN + "。\n" + NOR);
     me->pay_money(100);
     Lbird->move(environment(me));
     Lbird->set("owner",me->query("id"));
     Lbird->set_leader(me);
     me->set("level",1);
     me->set_temp("come-sum","YES");
     me->set_mlist(str,1);
     me->set("Lbird",str);
     } else write(GRN + "<" + HIG + "寵物妖精" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC + "好吧" + CYN + "﹐"
     HIC + "歡迎再度觀臨" + CYN + "。\n" + NOR);
     return;
}
int no_trade(string str, object me)
{
    me = this_player();
    command("say Sorry﹗"+me->name()+"﹐你並沒有認養執照ㄛ。\n");
    return 1;
}
