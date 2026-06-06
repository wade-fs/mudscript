//made by chad 修改 by semei
//20090410 存放pill npc
//將npc的kee gin sen 都設為1 避免有人拿來練功 by blazakira 2011/10/11

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string storeeq();

void create()
{
  object ob;
  set_name("蒼酷",({"store manager","manager"}));
  set("long","蒼酷 姓蒼名酷 為人天賦異稟 為現今武林失傳秘密絕學忍法-黑翼龍霸式之傳人
其武學之神秘 能納百川萬物於口袋中 因此又被江湖人士代稱之為武林[倉庫]\n");
  set("gender","男性");
  set("class","swordsman");
  set("title","$WHT$黑翼龍霸式傳人$NOR$");
  set("age",50);
  set("no_kill",1);
  set("no_fight",1);
  set("no_exp",1);
  set("score",1000000000);
  set("combat_exp",500000000);
  set("attitude","friendly");
  set("nickname","$HIC$武林奇才$NOR$");
  set("per",90);
  set("str",90);
  set("force",5000000);
  set("max_force",500000);
  set("mana",500000);
  set("max_mana",500000);
  set("atman",500000);
  set("max_atman",500000);
  set("force_factor",1000);
  set_temp("magic-manor/goldmagic",1);
  set_temp("magic-manor/woodmagic",1);
  set_temp("magic-manor/watermagic",1);
  set_temp("magic-manor/firemagic",1);
  set_temp("magic-manor/soilmagic",1);
  set("attribute","dark");
  set("dev_obj/dark",9999999);
  set("weapon/dark-full",999);
  setup();
  carry_object("/open/sky/obj/claw.c")->wield();
  carry_object("/open/beggar/obj/legs.c");
  carry_object("/open/dancer/obj/linrboots.c");
//  carry_object("/autoload/open-area/divine_belt.c");
//  carry_object("/autoload/open-area/turtle-shield.c");
  carry_object("/open/magic-manor/obj/dark-soul-dagger.c");
  carry_object("/autoload/open-area/m_pants.c");
  carry_object("/autoload/open-area/snake_amulet.c");
//  carry_object("/autoload/open-area/shawk.c");
  carry_object("/autoload/open-area/five-turn.c");
//  carry_object("/autoload/open-area/plate.c");
  carry_object("/open/capital/guard/gring");
//  carry_object("/autoload/open-area/light_cloak.c");
//  carry_object("/autoload/open-area/armband.c");
//  carry_object("/autoload/sky/peace_neck.c");
//  carry_object("/open/sky/guard/color_ring.c");
  carry_object("/autoload/open-area/super_hands")->wear();
  carry_object("/open/sky/obj/lucky_grasslink.c");
  carry_object("/u/b/blazakira/fix/autoload/divine_belt.c");
  carry_object("/u/b/blazakira/fix/autoload/turtle-shield.c");
  carry_object("/u/b/blazakira/fix/autoload/shawk.c");
  carry_object("/u/b/blazakira/fix/autoload/plate.c");
  carry_object("/u/b/blazakira/fix/autoload/light_cloak.c");
  carry_object("/u/b/blazakira/fix/autoload/armband.c");
  carry_object("/u/b/blazakira/fix/autoload/color_ring.c");
  carry_object("/u/b/blazakira/fix/autoload/peace_neck.c");
  all_inventory(this_object())->set("no_get",1);
  set("inquiry",([
    "倉庫":(: storeeq :),
    "黑翼龍霸式":"此乃非凡公子不傳絕學，乃你一平凡人所可了解？",
  ]));
  set("ann_die",1);
}

void init()
{
  object me = this_object();
  if(!me->query("weareq"))
  { 
    set("kee",1);
    set("eff_kee",1);
    set("max_kee",1);
    set("gin",1);
    set("eff_gin",1);
    set("max_gin",1);
    set("sen",1);
    set("eff_sen",1);
    set("max_sen",1);
    command("wield attribute-claw"); 
    command("wield all");
    me->set("weareq",1);
    ::init();
  }
  add_action("do_list","list");
  add_action("do_store","store");
  add_action("do_take","take");
  add_action("do_pay","pay");
}

void greeting()
{
  command("wear hands");
  command("wear color_ring");
  command("wear all");       
  command("suck soul");
  command("turn five");
  command("pray amulet");
}

int check( object obj )
{
  if(wizardp(this_player()))
    return 1;
  if( obj->is_character() || obj->is_corpse() )
    return notify_fail( "只能儲存物品。\n" );
  if( obj->query("no_save") )
    return notify_fail( "此物品被設定為無法儲存。\n" );
  if( obj->query_autoload() )
    return notify_fail( "此物品已有自動儲存的功能。\n" );
  if (obj->query("食物") || obj->query("液體"))
    return notify_fail("...這是倉庫，不是冰箱...\n");
  return 1;
}

int do_list()
{
  object ppl = this_player();
  if(ppl->query("mark/storeeq")==1)
  {
    ppl->start_more("/adm/daemons/saveeqd"->list());
    return 1;
  }
  else
  {
    command("sorry");
    command("say 你尚未幫我完成任務，恕我無法為您服務！");
    return 1;
  }
}

int do_store(string str)
{
  int amount;
  string item,name,name2;
  object obj2,env,obj;
  object ppl = this_player();
  env = environment(ppl);

  if (ppl->query("mark/storeeq"))
  {
    if (!str) return notify_fail(HIW + "" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你想存什麼東西？\n" + NOR);
    if (sscanf (str,"%d %s",amount,item)==2)
    {
      obj = present(item,ppl);
      if (!obj)
        return notify_fail(HIW + "" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你身上並沒有這項東西。\n" + NOR);
      if (!check(obj))
        return 0;
      if (!obj->query_amount()) 
        return notify_fail(HIW + "" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 這項東西不能被分開存放\n" + NOR);
      if (amount > obj->query_amount())
        return notify_fail(HIW + "" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你並沒有這麼多"+obj->query("name")+".\n" + NOR);
//以上為檢測物品本身是否能被存入. chad
      if(obj) //如果通過物品檢測要存入obj時開始做檢測. chad
      {
        if (amount == obj->query_amount())
        {
          message_vision(HIY + "$N將"+chinese_number(amount)+obj->query("unit")+obj->query("name")+HIY+"交給了$n" + HIY + "。\n" + NOR,ppl,this_object());
          if("/adm/daemons/saveeqd"->store(obj)==1){return 1;}
            return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 這位大俠，您的倉庫已經放滿囉！這東西先還給你，等你整理完倉庫再來存吧！\n" + NOR);
        }
        else
        {
          if(amount<=0)
          {
            command("slap "+ ppl->query("id"));
            return notify_fail(HIW + "" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: ..這位大俠，請別耍我！\n" + NOR);
          }
          obj -> set_amount( obj->query_amount() - amount );
          obj2 = new(base_name(obj));
          obj2-> set_amount(amount);
          message_vision(HIY + "$N將"+chinese_number(amount)+obj2->query("unit")+obj2->query("name")+"交給了$n\n" + NOR,ppl,this_object());
          if("/adm/daemons/saveeqd"->store(obj2)==1){return 1;}
          return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 這位大俠，您的倉庫已經放滿囉！這東西先還給你，等你整理完倉庫再來存吧！\n" + NOR);
        }
      }
    }
    obj = present( str, ppl );
    if( !obj ) 
      obj = present( str, env );
    if( !obj ) 
      return notify_fail(HIW + "" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你身上並沒有此項物品。\n" + NOR );
    if(!check(obj))
      return 0;
    message_vision(HIY + "$N將"+obj->query("name")+HIY + "全部交給了$n" + HIY + "。\n" + NOR,ppl,this_object());
    if("/adm/daemons/saveeqd"->store(obj)==1){return 1;}
    return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 這位大俠，您的倉庫已經放滿囉！這東西先還給你，等你整理完倉庫再來存吧！\n" + NOR);
  }
  else
    command("sorry");
  command("say 你似乎還沒完成我所交付之任務，很抱歉，我無法幫助你！" + NOR);
  ppl->save();
  return 1;
}

int do_take(string str)
{
  int i,h,amount,total;
  object obj,obj2,obj3,obj4;
  object ppl = this_player();

  h = atoi(str);

  if(ppl->query("mark/storeeq")==1)
  {
    if(!str) return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 請問你想取出哪一項目的物品呢？\n" + NOR);
    if( sscanf (str,"%d %d",amount,h)==2  && amount > 0 && h > 0)
    {
      obj = "/adm/daemons/saveeqd"->take(h);
      if(!obj)
      {
        return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 嗯，看來你沒有在我這邊存放這項物品唷！\n" + NOR);
      }

      total =  obj->query_amount();

      if(total > amount)
      {
        obj2 = new(base_name(obj));
        obj->set_amount(total-amount);
        obj2->set_amount(amount);
        "/adm/daemons/saveeqd"->store(obj);
        if(!obj2->move(ppl)) {
          "/adm/daemons/saveeqd"->store(obj2);
          return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你拿不動這些東西，請說你拿的動的數量哦。\n" + NOR);
        }
        message_vision("$N拿出"+chinese_number(amount)+obj2->query("unit")+"$n \n",ppl,obj2);
        return 1;
      }
      else if(total == amount)
      { 
        write("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 您已經將這項物品全數提領完畢囉！\n" + NOR);
        obj2 = new(base_name(obj));
        obj2 -> set_amount(amount);
        obj2 -> move(ppl);
        if(!obj2 -> move(ppl))
        {
          "/adm/daemons/saveeqd"->store(obj2);
          return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你好像拿不動東西。\n" + NOR);
        }
        return 1;
      }
      else
      {
        if(!obj -> move(ppl))
        {
          "/adm/daemons/saveeqd"->store(obj);
          return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你已經拿出你拿的動東西。\n" + NOR);
        }
        if(total == 0) //代表他不是數量物件，只能用迴圈取
        {
          string fileName = base_name(obj); 
          for(int j = 1 ; j < amount ; j++ ) // 一次最多取 1000 件，反正也拿不動
          {
            obj2 = "/adm/daemons/saveeqd"->take(h);
            if(!obj2)
            {
              return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 嗯，你並沒有在我這邊存放此類物品。\n" + NOR);
            }
            if(fileName != base_name(obj2)) {
              "/adm/daemons/saveeqd"->store(obj2);
              break;
            }
            if(!obj2 -> move(ppl))
            {
              "/adm/daemons/saveeqd"->store(obj2);
              return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你已經拿出你拿的動東西。\n" + NOR);
            }
          }
          message_vision("$N將所有的"+fileName->query("name")+"一併取出。\n",ppl);
          return 1;
        }
        write("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你要提領的這項物品，存放的數量似乎沒有這麼多。\n" + NOR);
        obj2 = new(base_name(obj));
        obj2->set_amount(total);
        obj->add_amount(-total);
        "adm/daemons/saveeqd"->store(obj2);
        return 1;
      }
    }
    if( sscanf (str,"%d %d",amount,h)==2  && amount <= 0)
    {
      command("slap "+ppl->query("id"));
      return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: ...你是來亂的嗎？請 type take 數量 物品項數！\n" + NOR);
    }
    if( sscanf (str,"%*d %d",amount,h)==1  &&  h<= 0)
    {
      return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 請問你想取出什麼項目呢？\n" + NOR);
    }
    if( sscanf (str,"%*d %d",amount,h)==1  &&  h > 0)
    {
      string fileName; 
      for(int j = 0 ; j < 1000 ; j++ ) // 一次最多取 1000 件，反正也拿不動
      {
        obj = "/adm/daemons/saveeqd"->take(h);
        if(!obj) break;
        if(undefinedp(fileName)) fileName = base_name(obj);
        if(fileName != base_name(obj)) {
          "/adm/daemons/saveeqd"->store(obj);
          break;
        }
        if(!obj)
        {
          return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 嗯，你並沒有在我這邊存放此類物品。\n" + NOR);
        }
        if(!obj -> move(ppl))
        {
          "adm/daemons/saveeqd"->store(obj);
          return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你已經拿不動這些東西，請說你拿的動的數量哦。\n" + NOR);
        }
      }
      if(undefinedp(fileName))
      {
        return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 嗯，你並沒有在我這邊存放此類物品。\n" + NOR);
      }
      message_vision("$N將所有的"+fileName->query("name")+"一併取出\n",ppl);
      return 1;
    }
    return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 很抱歉，我無法辨識您的需求，若有任何疑問可以問我有關[倉庫]的使用方式！\n");
  }
  return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你似乎還沒完成我所交付之任務，很抱歉，我無法幫助你！\n" + NOR); 
}

int do_pay()
{
  object me,ob;
  int coin,i;
  me=this_player();
  i=500000000;
  if("/adm/daemons/saveeqd"->queryMaxStore()>=20){return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道:很抱歉，你存放的物品已經到達上限，無法再增加。\n" + NOR);}
  if( !me->pay_money(i) )
  {
    command("hmm");
    return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 你的錢似乎不夠喔？\n" + NOR);
  }
  "/adm/daemons/saveeqd"->addMaxStore();
  command("smile");
  return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "蒼酷說道: 感謝您的使用，請 type list 看最大上限是否增加。\n" + NOR);
}

int accept_object(object ppl,object obj)
{
  ppl = this_player();
  if(!ppl->query("mark/storeeq")&&obj->query("kill_id")==ppl->query("id")&&obj->query("id")=="blackstone")
  {
    ppl->set("mark/storeeq",1);
    command("bow");
    command("say 謝謝您替我完成任務，為了答謝你，此倉庫任您使用！共有 list,take,store 三項指令可供使用。" + NOR);
    command("say 若大俠對倉庫的使用方式仍有疑問，可以再詢問我一次有關[倉庫]的問題！" + NOR);
    destruct (obj);
    log_file("open-area/can_storeeq", sprintf("%s(%s) 協助蒼酷解決問題 in %s\n",ppl->query("name"),ppl->query("id"), ctime(time()) ));
    return 1;
  }
  else if(!ppl->query("mark/storeeq")&&obj->query("kill_id")!=ppl->query("id")&&obj->query("id")=="blackstone")
  {
    command("hmm");
    command("say 非常謝謝你，但看來似乎不是你親手幫我找回的！但還是很謝謝您的熱心！");
    destruct(obj);
    return 0;
  }
  if(obj->query("id")=="coin"||obj->query("id")=="silver"||obj->query("id")=="gold")
  {
    command("spit "+ppl->query("id"));
    command("say 我不是乞丐！大俠此等行為也未免太小看我蒼某人!!");
    return 0;
  }
  command("say 多謝大俠將如此厚禮贈送給我，蒼某感激不盡！\n");
  destruct (obj);
  return 1;
}

string storeeq()
{
  object ppl = this_player();
  object obj = this_object();
  if(!ppl->query("mark/storeeq"))
  {
    command("hmm");
    return "" + HIY + "最近武林風波不斷，我所珍藏的一粒寶石也於日前與一忍法殺手頭目切磋武功之時遺失了。若你能代我找回此項物品並歸還於我，在下必定重重回報！\n" + NOR;
  }
  else 
  {
    write("" + CYN + "蒼酷說道:" + HIY + " 您可以 type store 即可以收藏您想收藏之物品， type list 即可了解目前存放的物品之數量及最大存放上限， type take 數字 即可拿出該樣物品全部數量。\n");
    write("" + CYN + "蒼酷說道:" + HIY + " 進階使用方式為 type take 數字一 數字二 則可拿出[數字二]之物品[數字一]的數量，請多加利用。\n" + NOR);
    return "" + HIY + "若想增加最大存放上限，請身上帶著五顆" + HIW + "鑽石" + HIY + "來找我，然後 type pay 即可。\n" + NOR;
  }
}
