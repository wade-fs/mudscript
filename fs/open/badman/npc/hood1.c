//修正偷竊函數do_steal不存在的問題 by blazakira 2011/4/5

#include <ansi.h>
inherit NPC;

string do_steal();

void create()
{
  set_name("小潑皮",({"hood"}) );
  set("long","一個整天在街頭上閒混閒逛的小混混。\n");

  set("gender","男性");
  set("age",25);
  set("attitude","badman");

  set_skill("dodge",10);
  set_skill("unarmed",15);
  set_temp("apply/attack",10);
  set_temp("apply/armor",10);
  set("combat_exp",300);

  set("chat_chance_combat",80);
  set("chat_msg_combat",({
     (:do_steal:)
  }));

  set("chat_chance",2);
  set("chat_msg",({
      "小潑皮一臉鳥樣的在你面前走了幾圈。\n",
      "小潑皮拍了拍你的肩膀，說道：喂！小兄弟、拿些錢來給老子花花啊。\n",
  }));

  setup();

  carry_object("/obj/cloth")->wear();
}

string do_steal()
{
  object ob;
  mixed enemy,item;
  string style,cstyle; //style錢的類型
  int i,j,money,del;
  ob = this_object();
  enemy = all_inventory(environment(ob)); //this_object()附近所有的objects
  i = sizeof(enemy); //objects數量
  j=random(i); //隨機找一個
  if(!enemy[j]->query_temp("no_steal",1) && enemy[j]->is_character() && !enemy[j]->is_corpse()) //物件沒有設定no_steal，不是死物，是角色，則偷錢
  {
    switch(random(3)+2) //選擇要偷的種類 //因為是較弱的npc 所以銀票以上不偷 by blazakira
    {
      case 0:
        style="diamond";
        cstyle="鑽石";
        break;
      case 1:
        style="cash";
        cstyle="銀票";
        break;
      case 2:
        style="gold";
        cstyle="黃金";
        break;
      case 3:
        style="silver";
        cstyle="銀子";
        break;
      default:
        style="coin";
        cstyle="銅錢";
        break;
    }
    
    if(present(style,enemy[j]))    //有此style類型的錢才偷
    {
      money=present(style,enemy[j])->query_amount();
      del=random(money)+1;
      message_vision(HIY + "\n$N被$n偷走 "+cstyle+" "+del+" "+present(style,enemy[j])->query("base_unit")+"！！\n\n" + NOR,enemy[j],ob);
      del=money-del; //扣掉被偷的
      present(style,enemy[j])->set_amount(del); //剩下來的
    }
  }
  return "";
}