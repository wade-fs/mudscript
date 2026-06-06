//增加裝備的英文表述 by blazakira 2011/4/4
//補上判斷dragon_gem換成戰功時 取消已穿戴所獲得的force加成 by blazakira 2011/8/4
//增加死亡訊息的表達 by blazakira 2011/11/9

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_help();
int query_level();
int helps();
int war_score;

string answer_war_score()
{
  int war_score;
  war_score=this_player()->query("war_score",1);
  return sprintf("你共有%d點戰功\點數。\n",war_score);
}

void create()
{
  object ob;
  set_name("李  喚",({"officer lee","officer","lee"}));
  set("long","他是專門給護國有功\的戰士授與獎勵,你可以用list 跟convert 換取。\n"+
    "戰功\物品升級請用 levelup 來查詢，且可help wareq來得知升級規則。\n古龍紋玉佩可以用gem give來換取戰功\。\n\n");
  set("gebder","男性");
  set("nickname",HIC + "首席戰情官" + NOR);
  set("combat_exp",100);
  set("inquiry",([
    "戰功\":(: answer_war_score :),
    "幫忙" : (: do_help :),
  ]));
  set("list",([
    "九轉熊蛇丸": ([
      "local":"/open/mogi/castle/obj/ninepill",
      "amount":500,
      "efficacy":"丹藥：回血",
      "war_score":2,
      "id":"snake pill",
    ]),
    "生生造化丹": ([
      "local":"/open/mogi/castle/obj/sspill",
      "amount":500,
      "efficacy":"丹藥：？？？",
      "war_score":3,
      "id":"sen sen pill",
    ]),
    "救命靈丹": ([
      "local":"/obj/standby-pill.c",
      "amount":10,
      "efficacy":"丹藥：服下後，在危難時期自動救命。（help 替身）",
      "war_score":200,
      "id":"standby-pill",
    ]),
    "治療之杖": ([
      "local":"/autoload/open-area/cure_staff",
      "amount":1,
      "efficacy":"武器：杖類，無攻擊力。",
      "war_score":1500,
      "id":"cure staff",
    ]),  
    "銀龍幻星鏈": ([
      "local":"/autoload/open-area/silver_dragon_whip",
      "amount":1,
      "efficacy":"武器：鞭類，冥蠱魔教、天道派特效。",
      "war_score":3700,
      "id":"silver dragon whip",
    ]),
    "血影摧心": ([
      "local":"/open/main/obj/unarmed-b",
      "amount":1,
      "efficacy":"武器：拳腳類，毒屬性。",
      "war_score":800,
      "id":"blood figring",
    ]),
    "火鳥脛甲": ([
      "local":"/autoload/open-area/bird_legging",
      "amount":1,
      "efficacy":"防具：天賦增加。", //天賦kar
      "war_score":3000,
      "id":"fire bird leggings",
    ]),
    "赤麟肩甲": ([
      "local":"/autoload/open-area/armband",
      "amount":1,
      "efficacy":"防具：天賦增加。", //天賦cor
      "war_score":3000,
      "id":"red chilin armband",
    ]),
    "金蠶手套": ([
      "local":"/open/main/obj/g_glove",
      "amount":5,
      "efficacy":"防具：防禦、攻擊強化。",
      "war_score":1500,
      "id":"gold gloves",
    ]),
    "閻月披風": ([
      "local":"/autoload/open-area/m_cloak",
      "amount":1,
      "efficacy":"防具：天賦增加。", //天賦cps
      "war_score":3000,
      "id":"dark moon cloak",
    ]),
    "神喻腰帶": ([
      "local":"/autoload/open-area/divine_belt",
      "amount":1,
      "efficacy":"防具：天賦增加。", //天賦per
      "war_score":3000,
      "id":"divine belt",
    ]),
    "英雄腕輪": ([
      "local":"/autoload/open-area/hero_hands",
      "amount":1,
      "efficacy":"防具：？？？",
      "war_score":7800,
      "id":"Hero Hands",
    ]),
    "聖靈戰甲": ([
      "local":"/autoload/open-area/plate",
      "amount":1,
      "efficacy":"防具：天賦增加。", //天賦spi
      "war_score":3000,
      "id":"holy ghost plate",
    ]),
    "青龍偃月刀": ([
      "local":"/open/main/obj/dragon-moon",
      "amount":1,
      "efficacy":"武器：刀類，攻擊特效。",
      "war_score":800,
      "id":"green dragon blade",
    ]),
    "留香扇": ([
      "local":"/open/main/obj/present-f",
      "amount":1,
      "efficacy":"武器：刺擊類，毀器特效。",
      "war_score":700,
      "id":"ancient fan",
    ]),
    "銀鷹頭盔": ([
      "local":"/autoload/open-area/shawk",
      "amount":1,
      "efficacy":"防具：攻擊力強化，回復效果，避雷。",
      "war_score":5000,
      "id":"silver-hawk",
    ]),
    "青龍護臂": ([
      "local":"/autoload/open-area/dragona",
      "amount":1,
      "efficacy":"防具：防禦力、法術、內力大幅強化。",
      "war_score":2700,
      "id":"dragon-armband",
    ]),
  ]));
  set("ann_die",1);
  setup();
}

int accept_object(object me,object ob)
{
  string letter_id;
  letter_id=ob->query("id");
  if(letter_id=="lee_letter")
  {
    destruct(ob);
    command("say 咦!我的信，嗯......多謝你啦");
    command("bow"+me->query("id"));
    me->add("taigan_exp",10);
    me->delete_temp("working");
    switch(random(3)){
      case 1:
        me->set("taigan_work",8);
        break;
      case 2:
        me->set("taigan_work",1);
        break;
      case 3:
        me->set("taigan_work",2);
        break;
    }
  }
  else {
    command("say 嗯???這不是給我的，你搞錯囉!!!");
    command("give"+ob->query("id")+me->query("id"));
  }
}

string do_help()
{
  int work,i,j,k;
  object me,ob,letter;
  me=this_player();
  ob=this_object();
  work=me->query("taigan_work");
  if(work!=7 || me->query_temp("working") ||me->query("class")!="taigan")
    return "我現在沒什麼事需要你幫忙，去看看別人需不需要吧。\n";
  else
  {
    switch(random(3))
    {
      case 1:
        new("/open/capital/room/sroom/obj/wu_letter")->move(me);
        me->set_temp("working",1);
        message_vision("給了$N一封信。\n",me);
        return "你來的正好，我這裡有封信要交給糧草總兵吳大人，你幫我跑一趟吧。\n";
        break;
      case 2:
        new("/open/capital/room/sroom/obj/yen_letter")->move(me);
        me->set_temp("working",1);
        message_vision("給了$N一封信。\n",me);
        return "你來的正好，我這裡有封信要交給東廠的嚴公公，你幫我跑一趟吧。\n";
        break;
      case 3:
        new("/open/capital/room/sroom/obj/chang_letter")->move(me);
        me->set_temp("working",1);
        message_vision("給了$N一封信。\n",me);
        return "你來的正好，我這裡有封信要交給東廠的張公公，你幫我跑一趟吧。\n";
        break;
    }
  }
}

void init()
{
  add_action("do_list","list");
  add_action("do_convert","convert");
  add_action("do_levelup","levelup");
  add_action("do_gem","gem");
}

int do_list(object me)
{
  string *name;
  int i;

  me=this_player();
  name = keys(query("list"));
  tell_object(this_player(),NOR + "目前所能換到的獎品：（請使用獎品" + HIY + "中文名稱" + NOR + "換取賞賜，且" + HIY + "數量有限" + NOR + "）\n");
  tell_object(this_player(),HIG + " ｛ 獎品(id) ｝              ｛ 所須戰功\點數 ｝｛效用｝\n" + NOR);
  for(i=0;i<sizeof(name);i++)
    tell_object(this_player(),sprintf("%10s(%-18s)%10d %10s\n",name[i],query("list/"+name[i]+"/id"),query("list/"+name[i]+"/war_score"),query("list/"+name[i]+"/efficacy")));
  return 1;
}

int do_convert(string weapon)
{
  object ob;
  if(this_player()->query("war_score")<=10)
  {
    command("say 沒功\勞要啥獎，早點回去睡吧!\n");
    return 1;
  }
  if(!query("list/"+weapon))
  {
     command("say 你想要什麼賞賜?\n");
     return 1;
  }
  if(query("list/"+weapon+"/amount")<=0)
  {
    command("say 這樣東西換完了，現在缺貨。\n");
    return 1;
  }
  if (this_player()->query("war_score") < query("list/"+weapon+"/war_score") ) {
    sprintf("你共有%d點護國戰功\點數。\n", war_score);
    command("say 等你戰功\足夠再來換吧！\n");
    return 1;
  }
  ob=new(query("list/"+weapon+"/local"));
//2002-12-30 修改 --by kalin
//  ob->add_amount(1);
  ob->set_amount(1);
  add("list/"+weapon+"/amount",-1);
  this_player()->add("war_score",-query("list/"+weapon+"/war_score"));
  ob->move(this_player());
  ob->set("no_drop",1);
  ob->set("no_give",1);
  message_vision( "$N拿給$n所要的"+ob->name()+"\n",this_object(),this_player());
  write_file("/log/war/convert",sprintf("%s(%s) 用戰功\換%s於 %s\n",
  this_player()->name(1),this_player()->query("id"),ob->name(),ctime(time())));
  return 1;
}

//以下新增戰功等級限制及升級制度 by neverend 2007-05-26

int do_levelup(string arg)
{
  object me,ob;
  int a1,a2,a3,a4,a5,ws;

  me=this_player();
  ob=this_object();

  a1=me->query("eq-mark/red-chilin-armband");
  a2=me->query("eq-mark/bird-legging");
  a3=me->query("eq-mark/divine-belt");
  a4=me->query("eq-mark/holy-ghost-plate");
  a5=me->query("eq-mark/dark-moon-cloak");

  ws=me->query("war_score");

  if( !arg )
    return notify_fail("\n請選一個數字來增加你的戰功\物品等級。\n\n\t【1】赤麟肩甲。\n\t【2】火鳥脛甲。\n\t【3】神喻腰帶。\n\t【4】聖靈戰甲。\n\t【5】閻月披風。\n\n其他相關指令levelup query 或 levelup help。\n");

  if( arg == "query" )
  {
    query_level();
  }

  if( arg == "help" )
  {
    helps();
  }

  if( arg == "1" )
  {
    if( a1 == 7 )
    {
      command("say "+me->name(1)+"的戰功\物品等級已經為最高等級了。");
    } else {
      if( a1 == 0 && ws > 10000 )
      {
        me->set("eq-mark/red-chilin-armband",1);
        me->add("war_score",-10000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "赤" + HIG + "麟" + HIC + "肩甲" + HIC + "等級提升為一級。");
        write_file("/log/war/r-c-armband",sprintf("%s(%s) 用戰功\將赤麟肩甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a1+1),ctime(time())));
        return 1;
      }
      if( a1 == 1 && ws > 20000 )
      {
        me->set("eq-mark/red-chilin-armband",2);
        me->add("war_score",-20000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "赤" + HIG + "麟" + HIC + "肩甲" + HIC + "等級提升為二級。");
        write_file("/log/war/r-c-armband",sprintf("%s(%s) 用戰功\將赤麟肩甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a1+1),ctime(time())));
        return 1;
      }
      if( a1 == 2 && ws > 40000 )
      {
        me->set("eq-mark/red-chilin-armband",3);
        me->add("war_score",-40000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "赤" + HIG + "麟" + HIC + "肩甲" + HIC + "等級提升為三級。");
        write_file("/log/war/r-c-armband",sprintf("%s(%s) 用戰功\將赤麟肩甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a1+1),ctime(time())));
        return 1;
      }
      if( a1 == 3 && ws > 80000 )
      {
        me->set("eq-mark/red-chilin-armband",4);
        me->add("war_score",-80000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "赤" + HIG + "麟" + HIC + "肩甲" + HIC + "等級提升為四級。");
        write_file("/log/war/r-c-armband",sprintf("%s(%s) 用戰功\將赤麟肩甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a1+1),ctime(time())));
        return 1;
      }
      if( a1 == 4 && ws > 120000 )
      {
        me->set("eq-mark/red-chilin-armband",5);
        me->add("war_score",-120000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "赤" + HIG + "麟" + HIC + "肩甲" + HIC + "等級提升為五級。");
        write_file("/log/war/r-c-armband",sprintf("%s(%s) 用戰功\將赤麟肩甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a1+1),ctime(time())));
        return 1;
      }
      if( a1 == 5 && ws > 200000 )
      {
        me->set("eq-mark/red-chilin-armband",6);
        me->add("war_score",-200000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "赤" + HIG + "麟" + HIC + "肩甲" + HIC + "等級提升為六級。");
        write_file("/log/war/r-c-armband",sprintf("%s(%s) 用戰功\將赤麟肩甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a1+1),ctime(time())));
        return 1;
      }
      if( a1 == 6 && ws > 300000 )
      {
        me->set("eq-mark/red-chilin-armband",7);
        me->add("war_score",-300000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "赤" + HIG + "麟" + HIC + "肩甲" + HIC + "等級提升為七級。");
        write_file("/log/war/r-c-armband",sprintf("%s(%s) 用戰功\將赤麟肩甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a1+1),ctime(time())));
        return 1;
      }
      else {
        command("say 戰功\不足夠升級唷！！");
      }
    }
  }

  if( arg == "2" )
  {
    if( a2 == 7 )
    {
      command("say "+me->name(1)+"的戰功\物品等級已經為最高等級了。");
    } else {
      if( a2 == 0 && ws > 10000 )
      {
        me->set("eq-mark/bird-legging",1);
        me->add("war_score",-10000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "火鳥" + HIW + "脛甲" + HIC + "等級提升為一級。");
        write_file("/log/war/b-legging",sprintf("%s(%s) 用戰功\將火鳥脛甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a2+1),ctime(time())));
        return 1;
      }
      if( a2 == 1 && ws > 20000 )
      {
        me->set("eq-mark/bird-legging",2);
        me->add("war_score",-20000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "火鳥" + HIW + "脛甲" + HIC + "等級提升為二級。");
        write_file("/log/war/b-legging",sprintf("%s(%s) 用戰功\將火鳥脛甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a2+1),ctime(time())));
        return 1;
      }
      if( a2 == 2 && ws > 40000 )
      {
        me->set("eq-mark/bird-legging",3);
        me->add("war_score",-40000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "火鳥" + HIW + "脛甲" + HIC + "等級提升為三級。");
        write_file("/log/war/b-legging",sprintf("%s(%s) 用戰功\將火鳥脛甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a2+1),ctime(time())));
        return 1;
      }
      if( a2 == 3 && ws > 80000 )
      {
        me->set("eq-mark/bird-legging",4);
        me->add("war_score",-80000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "火鳥" + HIW + "脛甲" + HIC + "等級提升為四級。");
        write_file("/log/war/b-legging",sprintf("%s(%s) 用戰功\將火鳥脛甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a2+1),ctime(time())));
        return 1;
      }
      if( a2 == 4 && ws > 120000 )
      {
        me->set("eq-mark/bird-legging",5);
        me->add("war_score",-120000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "火鳥" + HIW + "脛甲" + HIC + "等級提升為五級。");
        write_file("/log/war/b-legging",sprintf("%s(%s) 用戰功\將火鳥脛甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a2+1),ctime(time())));
        return 1;
      }
      if( a2 == 5 && ws > 200000 )
      {
        me->set("eq-mark/bird-legging",6);
        me->add("war_score",-200000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "火鳥" + HIW + "脛甲" + HIC + "等級提升為六級。");
        write_file("/log/war/b-legging",sprintf("%s(%s) 用戰功\將火鳥脛甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a2+1),ctime(time())));
        return 1;
      }
      if( a2 == 6 && ws > 300000 )
      {
        me->set("eq-mark/bird-legging",7);
        me->add("war_score",-300000);
        command("chat 恭喜"+me->name(1)+"的" + HIR + "火鳥" + HIW + "脛甲" + HIC + "等級提升為七級。");
        write_file("/log/war/b-legging",sprintf("%s(%s) 用戰功\將火鳥脛甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a2+1),ctime(time())));
        return 1;
      }
      else {
        command("say 戰功\不足夠升級唷！！");
      }
    }
  }

  if( arg == "3" )
  {
    if( a3 == 7 )
    {
      command("say "+me->name(1)+"的戰功\物品等級已經為最高等級了。");
    } else {
      if( a3 == 0 && ws > 10000 )
      {
        me->set("eq-mark/divine-belt",1);
        me->add("war_score",-10000);
        command("chat 恭喜"+me->name(1)+"的" + HIC + "神喻" + HIW + "腰帶" + HIC + "等級提升為一級。");
        write_file("/log/war/d-belt",sprintf("%s(%s) 用戰功\將神喻腰帶升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a3+1),ctime(time())));
        return 1;
      }
      if( a3 == 1 && ws > 20000 )
      {
        me->set("eq-mark/divine-belt",2);
        me->add("war_score",-20000);
        command("chat 恭喜"+me->name(1)+"的" + HIC + "神喻" + HIW + "腰帶" + HIC + "等級提升為二級。");
        write_file("/log/war/d-belt",sprintf("%s(%s) 用戰功\將神喻腰帶升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a3+1),ctime(time())));
        return 1;
      }
      if( a3 == 2 && ws > 40000 )
      {
        me->set("eq-mark/divine-belt",3);
        me->add("war_score",-40000);
        command("chat 恭喜"+me->name(1)+"的" + HIC + "神喻" + HIW + "腰帶" + HIC + "等級提升為三級。");
        write_file("/log/war/d-belt",sprintf("%s(%s) 用戰功\將神喻腰帶升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a3+1),ctime(time())));
        return 1;
      }
      if( a3 == 3 && ws > 80000 )
      {
        me->set("eq-mark/divine-belt",4);
        me->add("war_score",-80000);
        command("chat 恭喜"+me->name(1)+"的" + HIC + "神喻" + HIW + "腰帶" + HIC + "等級提升為四級。");
        write_file("/log/war/d-belt",sprintf("%s(%s) 用戰功\將神喻腰帶升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a3+1),ctime(time())));
        return 1;
      }
      if( a3 == 4 && ws > 120000 )
      {
        me->set("eq-mark/divine-belt",5);
        me->add("war_score",-120000);
        command("chat 恭喜"+me->name(1)+"的" + HIC + "神喻" + HIW + "腰帶" + HIC + "等級提升為五級。");
        write_file("/log/war/d-belt",sprintf("%s(%s) 用戰功\將神喻腰帶升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a3+1),ctime(time())));
        return 1;
      }
      if( a3 == 5 && ws > 200000 )
      {
        me->set("eq-mark/divine-belt",6);
        me->add("war_score",-200000);
        command("chat 恭喜"+me->name(1)+"的" + HIC + "神喻" + HIW + "腰帶" + HIC + "等級提升為六級。");
        write_file("/log/war/d-belt",sprintf("%s(%s) 用戰功\將神喻腰帶升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a3+1),ctime(time())));
        return 1;
      }
      if( a3 == 6 && ws > 300000 )
      {
        me->set("eq-mark/divine-belt",7);
        me->add("war_score",-300000);
        command("chat 恭喜"+me->name(1)+"的" + HIC + "神喻" + HIW + "腰帶" + HIC + "等級提升為七級。");
        write_file("/log/war/d-belt",sprintf("%s(%s) 用戰功\將神喻腰帶升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a3+1),ctime(time())));
        return 1;
      }
      else {
        command("say 戰功\不足夠升級唷！！");
      }
    }
  }

  if( arg == "4" )
  {
    if( a4 == 7 )
    {
      command("say "+me->name(1)+"的戰功\物品等級已經為最高等級了。");
    } else {
      if( a4 == 0 && ws > 10000 )
      {
        me->set("eq-mark/holy-ghost-plate",1);
        me->add("war_score",-10000);
        command("chat 恭喜"+me->name(1)+"的" + HIW + "聖靈戰甲" + HIC + "等級提升為一級。");
        write_file("/log/war/h-g-plate",sprintf("%s(%s) 用戰功\將聖靈戰甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a4+1),ctime(time())));
        return 1;
      }
      if( a4 == 1 && ws > 20000 )
      {
        me->set("eq-mark/holy-ghost-plate",2);
        me->add("war_score",-20000);
        command("chat 恭喜"+me->name(1)+"的" + HIW + "聖靈戰甲" + HIC + "等級提升為二級。");
        write_file("/log/war/h-g-plate",sprintf("%s(%s) 用戰功\將聖靈戰甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a4+1),ctime(time())));
        return 1;
      }
      if( a4 == 2 && ws > 40000 )
      {
        me->set("eq-mark/holy-ghost-plate",3);
        me->add("war_score",-40000);
        command("chat 恭喜"+me->name(1)+"的" + HIW + "聖靈戰甲" + HIC + "等級提升為三級。");
        write_file("/log/war/h-g-plate",sprintf("%s(%s) 用戰功\將聖靈戰甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a4+1),ctime(time())));
        return 1;
      }
      if( a4 == 3 && ws > 80000 )
      {
        me->set("eq-mark/holy-ghost-plate",4);
        me->add("war_score",-80000);
        command("chat 恭喜"+me->name(1)+"的" + HIW + "聖靈戰甲" + HIC + "等級提升為四級。");
        write_file("/log/war/h-g-plate",sprintf("%s(%s) 用戰功\將聖靈戰甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a4+1),ctime(time())));
        return 1;
      }
      if( a4 == 4 && ws > 120000 )
      {
        me->set("eq-mark/holy-ghost-plate",5);
        me->add("war_score",-120000);
        command("chat 恭喜"+me->name(1)+"的" + HIW + "聖靈戰甲" + HIC + "等級提升為五級。");
        write_file("/log/war/h-g-plate",sprintf("%s(%s) 用戰功\將聖靈戰甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a4+1),ctime(time())));
        return 1;
      }
      if( a4 == 5 && ws > 200000 )
      {
        me->set("eq-mark/holy-ghost-plate",6);
        me->add("war_score",-200000);
        command("chat 恭喜"+me->name(1)+"的" + HIW + "聖靈戰甲" + HIC + "等級提升為六級。");
        write_file("/log/war/h-g-plate",sprintf("%s(%s) 用戰功\將聖靈戰甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a4+1),ctime(time())));
        return 1;
      }
      if( a4 == 6 && ws > 300000 )
      {
        me->set("eq-mark/holy-ghost-plate",7);
        me->add("war_score",-300000);
        command("chat 恭喜"+me->name(1)+"的" + HIW + "聖靈戰甲" + HIC + "等級提升為七級。");
        write_file("/log/war/h-g-plate",sprintf("%s(%s) 用戰功\將聖靈戰甲升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a4+1),ctime(time())));
        return 1;
      }
      else {
        command("say 戰功\不足夠升級唷！！");
      }
    }
  }

  if( arg == "5" )
  {
    if( a5 == 7 )
    {
    command("say "+me->name(1)+"的戰功\物品等級已經為最高等級了。");
    } else {
      if( a5 == 0 && ws > 10000 )
      {
        me->set("eq-mark/dark-moon-cloak",1);
        me->add("war_score",-10000);
        command("chat 恭喜"+me->name(1)+"的" + HIB + "閻"+HIY + "月"+HIW + "披風" + HIC + "等級提升為一級。");
        write_file("/log/war/d-m-cloak",sprintf("%s(%s) 用戰功\將閻月披風升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a5+1),ctime(time())));
        return 1;
      }
      if( a5 == 1 && ws > 20000 )
      {
        me->set("eq-mark/dark-moon-cloak",2);
        me->add("war_score",-20000);
        command("chat 恭喜"+me->name(1)+"的" + HIB + "閻"+HIY + "月"+HIW + "披風" + HIC + "等級提升為二級。");
        write_file("/log/war/d-m-cloak",sprintf("%s(%s) 用戰功\將閻月披風升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a5+1),ctime(time())));
        return 1;
      }
      if( a5 == 2 && ws > 40000 )
      {
        me->set("eq-mark/dark-moon-cloak",3);
        me->add("war_score",-40000);
        command("chat 恭喜"+me->name(1)+"的" + HIB + "閻"+HIY + "月"+HIW + "披風" + HIC + "等級提升為三級。");
        write_file("/log/war/d-m-cloak",sprintf("%s(%s) 用戰功\將閻月披風升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a5+1),ctime(time())));
        return 1;
      }
      if( a5 == 3 && ws > 80000 )
      {
        me->set("eq-mark/dark-moon-cloak",4);
        me->add("war_score",-80000);
        command("chat 恭喜"+me->name(1)+"的" + HIB + "閻"+HIY + "月"+HIW + "披風" + HIC + "等級提升為四級。");
        write_file("/log/war/d-m-cloak",sprintf("%s(%s) 用戰功\將閻月披風升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a5+1),ctime(time())));
        return 1;
      }
      if( a5 == 4 && ws > 120000 )
      {
        me->set("eq-mark/dark-moon-cloak",5);
        me->add("war_score",-120000);
        command("chat 恭喜"+me->name(1)+"的" + HIB + "閻"+HIY + "月"+HIW + "披風" + HIC + "等級提升為五級。");
        write_file("/log/war/d-m-cloak",sprintf("%s(%s) 用戰功\將閻月披風升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a5+1),ctime(time())));
        return 1;
      }
      if( a5 == 5 && ws > 200000 )
      {
        me->set("eq-mark/dark-moon-cloak",6);
        me->add("war_score",-200000);
        command("chat 恭喜"+me->name(1)+"的" + HIB + "閻"+HIY + "月"+HIW + "披風" + HIC + "等級提升為六級。");
        write_file("/log/war/d-m-cloak",sprintf("%s(%s) 用戰功\將閻月披風升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a5+1),ctime(time())));
        return 1;
      }
      if( a5 == 6 && ws > 300000 )
      {
        me->set("eq-mark/dark-moon-cloak",7);
        me->add("war_score",-300000);
        command("chat 恭喜"+me->name(1)+"的" + HIB + "閻"+HIY + "月"+HIW + "披風" + HIC + "等級提升為七級。");
        write_file("/log/war/d-m-cloak",sprintf("%s(%s) 用戰功\將閻月披風升到「%s」級於 %s\n",this_player()->name(1),this_player()->query("id"),chinese_number(a5+1),ctime(time())));
        return 1;
      }
      else {
        command("say 戰功\不足夠升級唷！！");
      }
    }
  }
  return 1;
}

int query_level()
{
  object me,ob;
  int a1,a2,a3,a4,a5;

  me=this_player();
  ob=this_object();

  a1=me->query("eq-mark/red-chilin-armband");
  a2=me->query("eq-mark/bird-legging");
  a3=me->query("eq-mark/divine-belt");
  a4=me->query("eq-mark/holy-ghost-plate");
  a5=me->query("eq-mark/dark-moon-cloak");

  if( !me->query("eq-mark") )
  {
    message_vision(HIW + "\t未有任何戰功\物品升級!!\n" + NOR,me);
//  helps();
  } else {
    command("say "+me->name(1)+"所有的戰功\物品等級提升如以下所列：");
//  message_vision(HIY + "\t李  喚說道：所有的戰功\物品等級提升如以下所列：\n" + NOR,me);
  if( a1 > 0 )
    message_vision("\t$N的" + HIR + "赤" + HIG + "麟" + HIC + "肩甲" + NOR + "戰功\等級為「" + HIM+chinese_number(a1)+NOR + "」級。\n",me);
  if( a2 > 0 )
    message_vision("\t$N的" + HIR + "火鳥" + HIW + "脛甲" + NOR + "戰功\等級為「" + HIM+chinese_number(a2)+NOR + "」級。\n",me);
  if( a3 > 0 )
    message_vision("\t$N的" + HIC + "神喻" + HIW + "腰帶" + NOR + "戰功\等級為「" + HIM+chinese_number(a3)+NOR + "」級。\n",me);
  if( a4 > 0 )
    message_vision("\t$N的" + HIW + "聖靈戰甲" + NOR + "戰功\等級為「" + HIM+chinese_number(a4)+NOR + "」級。\n",me);
  if( a5 > 0 )
    message_vision("\t$N的" + HIB + "閻"+HIY + "月"+HIW + "披風" + NOR + "戰功\等級為「" + HIM+chinese_number(a5)+NOR + "」級。\n",me);
  }
  return 1;
}

int helps()
{
  object me,ob;

  me=this_player();
  ob=this_object();

  message_vision("
  戰功\一級需   10000 點戰功\升級。
  戰功\二級需   20000 點戰功\升級。
  戰功\三級需   40000 點戰功\升級。
  戰功\四級需   80000 點戰功\升級。
  戰功\五級需  120000 點戰功\升級。
  戰功\六級需  200000 點戰功\升級。
  戰功\七級需  300000 點戰功\升級。
  \n",me);
  return 1;
}

int do_gem(string arg)
{
  object me,ob;

  me=this_player();
  ob=this_object();

  if( !arg )
    return notify_fail("你想做啥？\n");

  if( arg == "give" )
  {
    if( present("dragon_gem",me) )
    {
      if( me->query_temp("have_wear_dragongem") ) { //如果裝備在身上時 需刪除裝備加成
        if(me->query("class")=="fighter")
          me->add_temp("apply/force",-50);
        else
          me->add_temp("apply/force",-10);
        me->delete_temp("have_wear_dragongem");
      }
      destruct(present("dragon_gem",me));
      command("say 看在這東西還有點進貢的價值，賞個五點戰功\給你吧!!");
      write_file("/log/get_war/gem",sprintf("%s(%s)  得到五點戰功\於 %s\n",me->name(1),me->query("id"),ctime(time())));
      me->add("war_score",5);
    } else {
      command("say 你沒有我要的東西，沒事別來煩！");
    }
  } else {
    command("say 打個指令都會錯，快加強打字練習吧！");
  }
  return 1;
}
