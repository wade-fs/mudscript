//增加 獨孤嵊人頭的獎勵 by blazakira 2012/8/18

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string do_menu();
string do_can();

int accept_object (object me,object ob)
{
  object ob2;
  if(ob->query("id") == "sa-head")   //獨孤嵊
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/bellstar.c");
    ob2->add_amount(30000);
    ob2->move(me);
    me->add("bellicosity", 500);
    return 1;
  }
  if(ob->query("id") == "maiu-head")   //苗王
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/bellstar.c");
    ob2->add_amount(999);
    ob2->move(me);
    me->add("bellicosity", 100);
    if (me->query("combat_exp") < 50000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1000);
      me->add("potential", 500);
    }
    return 1;
  }
  if(ob->query("id") == "snow token") 
  {
    if (me->query_temp("mission2") == 3)
    {
      message_vision(" 李三笑將聖物收下來，仔細檢查了一下\n",me);
      command("say 太好了，左青龍，右雷虎，這是幽冥之壺給你吧，不用還了，省得有人老來煩我\n");
      destruct(ob);
      ob2=new("/open/killer/obj/can.c");
      ob2->move(me);
      me->set_temp("mission2",4);
      return 1;
    }
  }
  if(ob->query("id") == "nija_head")   // 忍者
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/s_pill.c");
    ob2->add_amount(24);
    ob2->move(me);
    ob2=new("/open/killer/obj/bellstar.c");
    ob2->add_amount(999);
    ob2->move(me);
    me->add("bellicosity", 100);
    if (me->query("combat_exp") < 50000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1000);
      me->add("potential", 500);
    }
    return 1;
  }
  if(ob->query("id") == "sword_head")   // 仙劍七子
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！就讓我來幫你轉換內力吧！\n");
    message_vision("只見，李三笑使出黑牙神功\奧義----化氣成靈！！\n",me);
    destruct(ob);
    message_vision("由$N體內冒出一道白氣，在李三笑的轉換之下，化成紫氣鑽回體內\n",me);
    if (me->query("max_atman") < 3000)
    {
      me->add("max_force",-5);
      me->add("max_atman",5);
      return 1;
    }
    message_vision("那道紫氣在接觸$N的同時，再次化為白氣\n",me);
    command("say 唉。。。我的能力不足以幫你轉換靈力了！");
    return 1;
  }
  if(ob->query("id") == "killer_wanted")   // 殺手人頭
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/s_pill.c");
    ob2->add_amount(99);
    ob2->move(me);
    ob2=new("/open/killer/obj/hate_knife.c");
    ob2->add_amount(999);
    ob2->move(me);
    ob2=new("/open/killer/obj/bellstar.c");
    ob2->add_amount(999);
    ob2->move(me);
    me->add("bellicosity", 500);
    if (me->query("combat_exp") < 400000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1500);
      me->add("potential", 1000);
    }
    return 1;
  }
  if(ob->query("id") == "zhang-head")    // 張淵
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/bellstar.c");
    ob2->add_amount(999);
    ob2->move(me);
    me->add("bellicosity", 100);
    if (me->query("combat_exp") < 50000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1000);
      me->add("potential", 500);
    }
    return 1;
  }
  if(ob->query("id") == "hou_head")  // 完顏宏烈
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/bellstar.c");
    ob2->add_amount(999);
    ob2->move(me);
    ob2=new("/open/killer/memory/static.c");
    ob2->move(me);
    me->add("bellicosity", 100);
    if (me->query("combat_exp") < 50000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1000);
      me->add("potential", 500);
    }
    return 1;
  }
  if(ob->query("id") == "fu_head")   // 鳳姑
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/hate_knife.c");
    ob2->add_amount(999);
    ob2->move(me);
    ob2=new("/open/killer/obj/s_pill.c");
    ob2->add_amount(29);
    ob2->move(me);
    me->add("bellicosity", 100);
    if (me->query("combat_exp") < 50000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1000);
      me->add("potential", 500);
    }
    return 1;
  }
  if(ob->query("id") == "fire-king-head")   // 焚天魔王
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/fire-knife.c");
    ob2->move(me);
    me->add("bellicosity", 300);
    if (me->query("combat_exp") < 95000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 3000);
      me->add("potential", 1000);
    }
    return 1;
  }
  if(ob->query("id") == "tiger-head")   // 獨角虎
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/hate_knife.c");
    ob2->add_amount(999);
    ob2->move(me);
    ob2=new("/open/killer/obj/s_pill.c");
    ob2->add_amount(29);
    ob2->move(me);
    me->add("bellicosity", 100);
    if (me->query("combat_exp") < 50000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1000);
      me->add("potential", 500);
    }
    return 1;
  }
  if(ob->query("id") == "zhang-z-head")   // 張繼
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/mon/obj/mon-pill.c");
    ob2->add_amount(4);
    ob2->move(me);
    me->add("bellicosity", 200);
    if (me->query("combat_exp") < 95000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1500);
      me->add("potential", 1000);
    }
    return 1;
  }
  if(ob->query("id") == "liu-head")   // 劉信
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/mon/obj/mon-pill.c");
    ob2->add_amount(4);
    ob2->move(me);
    me->add("bellicosity", 200);
    if (me->query("combat_exp") < 95000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1500);
      me->add("potential", 1000);
    }
    return 1;
  }
  if(ob->query("id") == "ra-head")   // 雷霸
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/mon/obj/mon-pill.c");
    ob2->add_amount(9);
    ob2->move(me);
    me->add("bellicosity", 200);
    if (me->query("combat_exp") < 95000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1500);
      me->add("potential", 1000);
    }
    return 1;
  }
  if(ob->query("id") == "mechoufen-head")   // 梅超風 
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/s_pill.c");
    ob2->add_amount(99);
    ob2->move(me);
    me->add("bellicosity", 300);
    if (me->query("combat_exp") < 600000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 2000);
      me->add("potential", 1500);
    }
    return 1;
  }
  if(ob->query("id") == "lin-head")   // 林宏昇
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/hate_knife.c");
    ob2->add_amount(9999);
    ob2->move(me);
    me->add("bellicosity", 300);
    if (me->query("combat_exp") < 95000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 2000);
      me->add("potential", 1500);
    }
    return 1;
  }
  if(ob->query("id") == "master-snake-head")   // 蛇郎君
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/soul-hands.c");
    ob2->move(me);
    me->add("bellicosity", 300);
    if (me->query("combat_exp") < 1000000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 3000);
      me->add("potential", 2000);
    }
    return 1;
  }
  if(ob->query("id") == "dragon-head")   // 黃金甲龍
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2= new( "/open/fire-hole/obj/b-pill.c" );  //藍龍精元
    ob2->move(me);
    ob2= new( "/open/fire-hole/obj/r-pill.c" );  //紅龍精元
    ob2->move(me);  
    ob2= new( "/open/fire-hole/obj/p-pill.c" );  //毒龍精元
    ob2->move(me);
    ob2= new( "/open/fire-hole/obj/w-pill.c" );  //白龍精元
    ob2->move(me);  
    ob2= new( "/open/fire-hole/obj/g-pill.c" );  //綠龍精元
    ob2->move(me);  
    ob2= new( "/open/fire-hole/obj/y-pill.c" );  //黃龍精元
    ob2->move(me);
    me->add("bellicosity", 300);
    if (me->query("combat_exp") < 95000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 3000);
      me->add("potential", 2000);
    }
    return 1;
  }
  if(ob->query("id") == "seven-dark-head")   // 七魔將
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/atman_pill.c");
    ob2->add_amount(14);
    ob2->move(me);
    me->add("bellicosity", 300);
    if (me->query("combat_exp") < 95000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 3000);
      me->add("potential", 2000);
    }
    return 1;
  }
  if(ob->query("id") == "black-ghost-head")   // 黑白雙剎
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/atman_pill.c");
    ob2->add_amount(29);
    ob2->move(me);
    me->add("bellicosity", 300);
    if (me->query("combat_exp") < 95000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 3000);
      me->add("potential", 2000);
    }
    return 1;
  }
  if(ob->query("id") == "white-ghost-head")   // 黑白雙剎
  {
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/atman_pill.c");
    ob2->add_amount(29);
    ob2->move(me);
    me->add("bellicosity", 300);
    if (me->query("combat_exp") < 95000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 3000);
      me->add("potential", 2000);
    }
    return 1;
  }
  if(ob->query("id") == "yar_head")  // 葉雙
  {
    if (me->query_temp("mission3") != 6)
    {
      command("say 居然敢叫別人幫你拿！可惡！看掌！！\n");
      message_vision(" 李三笑一掌將$N打飛\n",me);
      me->add("kee",(me->query("kee"))/2);
      me->move("/open/killer/home/ru1.c");
      return 0;
    }
    message_vision(" 李三笑將人頭收下來，仔細檢查了一下\n",me);
    command("say 果然不是造假的人頭，很好！酬金給你吧\n");
    destruct(ob);
    ob2=new("/open/killer/obj/s_pill.c");
    ob2->add_amount(9);
    ob2->move(me);
    ob2=new("/open/killer/weapon/k_cloth3.c");
    ob2->move(me);
    ob2=new("/open/killer/weapon/k_arm3.c");
    ob2->move(me);
    ob2=new("/open/killer/weapon/k_head3.c");
    ob2->move(me);
    me->add("bellicosity", 100);
    if (me->query("combat_exp") < 50000) 
    {
      command("say 依你這點能耐也能殺的死他, 真是不簡單, 讓我給你額外的獎賞吧!!\n");
      me->add("combat_exp", 1000);
      me->add("potential", 500);
    }
    return 1;
  }
  return 0;
}

void create()
{
  set_name("李三笑",({"king-lee","lee"}));
  set("long","傳說此人曾為魔教的長老，後來因故加入黑牙聯。\n"+
    "目前似乎負責傳達殺手目標物的名單(menu)\n");
  set("gender","男性");
  set("class","poisoner");
  set("nickname", HIG "幽冥鬼王" NOR);
  set("combat_exp",700000);
  set("attitude","heroism");
  set("age",60);
  set("str", 40);
  set("cor", 34);
  set("cps", 30);
  set("per", 30);
  set("int", 30);
  set("force",1800);
  set("max_kee",3500);
  set("kee",3500);
  set("max_force",1800);
  set_skill("move",80);
  set_skill("force",90);
  set_skill("dodge",100);
  set_skill("parry",70);
  set_skill("poison",60);
  set_skill("throwing",80);
  set_skill("rain-throwing",80);
  set_skill("poisonforce",99);
  set("force_factor",10);
  set_skill("coldpoison",80);
  set_skill("nine-steps",100);
  map_skill("throwing","rain-throwing");
  map_skill("dodge","nine-steps");
  map_skill("move","nine-steps");
  set_skill("ming-snake",60);
  set("inquiry",([
      "menu" : (: do_menu :),
      "借幽冥之壺" : (: do_can :),
      "雪泉聖物" : "雪泉聖物自然藏在雪蒼山中，你可以先到那裝死的獨孤愁的陵寢看看\n",
      "葉秀殺"   : "真是超級高手，我完全不是他的對手\n",
  ]));
  setup();
  carry_object("/open/killer/obj/lustar")->set_amount(200);
  add_money("gold",10);
}

string do_menu()
{
  object me = this_player();
  object ob;

  tell_object(me,"目前工作不多，只有幾件工作\n");
  tell_object(me,"想接就看紙上所寫的名單，包含酬金\n");
  if(me->query_temp("menuget") !=1)
  {
    ob=new("/open/killer/obj/killmenu.c");
    me->set_temp("menuget",1);
    ob->move(me);
  }
  return "把人頭給我，我就給你酬金\n";
}

string do_can()
{
  object me = this_player();
  object ob;

  if(me->query("class") == "killer")
  {
    if(me->query_temp("mission2") == 3)
    {
      return "還愣在那幹嘛，快去雪蒼的獨孤愁陵寢幫我找雪泉聖物\n";
    }
    if(me->query_temp("mission2") != 2)
    {
      return "幹嘛！無聊，沒事找事做呀！！";
    }
    if(me->query_temp("mission2") ==2)
    {
      tell_object(me,"可惡！那老太婆沒事找事做。。。。\n");
      tell_object(me,"想借可以，我想得到雷虎之氣，幫我拿個雪泉聖物吧\n");
      me->set_temp("mission2",3);
      return "把東西給我，我就給你幽冥之壺\n";
    }
  }
  command("waggle "+me->query("id"));
  return "憑什麼借給你？\n";
}
