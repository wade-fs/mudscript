//written by AceLan..../u/a/acelan/npc/fall.c
//Rewrite By AceLan fall.c 98.7.16...加強他的武功多變性...
//Motify by AceLan 98/11/1 增加弓箭的製造
//修正道具位置的錯誤 應為公開位置而非原設計wiz的目錄下(原位置已不存在) by blazakira 2011/3/11

#include "/open/open.h"
#include <ansi.h>

inherit F_VENDOR;

string make_weapon();
int init_weapon();
int about_weapon();
int in_combat();
int scholar_finger();
object reload_weapon( object);

void create()
{
   object ob;
   
   set_name("楚勝秋",({"zhu fall", "zhu", "fall"}));
   set("long", @LONG
迷樣之武林高手, 以(製作武器)聞名江湖。據說他曾以(儒門)失傳
已久之絕招與人對決戰, 大敗其對手。
LONG);
   set("nickname", "鬼斧神工");
   set("race","人類");
   set("gender","男性");
   set("combat_exp",500000);
   set("attitude","friendly");
   set("age",50);
   set("force_factor", 10);

   set("max_gin", 2000);
   set("eff_gin", 2000);
   set("gin", 2000);
   set("max_kee", 2000);
   set("eff_kee", 2000);
   set("kee", 2000);
   set("max_sen", 2000);
   set("eff_sen", 2000);
   set("sen", 2000);
   set("max_force", 2000);
   set("force", 2000);
   set("max_atman", 2000);
   set("atman", 2000);
   set("max_mana", 2000);
   set("mana", 2000);

   set("str", 30);
   set("cor", 30);
   set("per", 30);
   set("int", 30);
   set("cps", 30);
   set("con", 30);
   set("spi", 30);
   set("kar", 30);
   set("family/family_master", "小蛋蛋");
   set("family/family_name", "儒門");

   set_skill("force", 100);
   set_skill("dodge", 100);
   set_skill("move", 100);
   set_skill("parry", 100);
   set_skill("magic", 100);
   set_skill("unarmed", 100);
   set_skill("stabber", 100);
   set_skill("sword", 100);
   set_skill("blade", 100);
   set_skill("dagger", 100);
   set_skill("plan", 100);

   //儒門
   set_skill("literate", 100);                  //身為儒門, 不會讀書怎行...
   set_skill("knowpen", 100);
   set_skill("poetforce", 100);
   set_skill("winter-steps", 100);
   set_skill("god-plan", 100);
   //仙劍
   set_skill("shasword", 100);
   set_skill("shaforce", 100);
   set_skill("sha-steps", 100);
   //京城
   set_skill("dragon-dagger", 100);
   set_skill("oneforce", 100);
   set_skill("chen-steps", 100);
   //金刀
   set_skill("fast-blade", 100);
   set_skill("gold-blade", 100);
   set_skill("fly-steps", 100);
   set_skill("sixforce", 100);
   //段家
   set_skill("six-fingers", 100);
   set_skill("sunforce", 100);
   set_skill("linpo-steps", 100);
   //惡人
   set_skill("badstrike", 100);
   set_skill("badforce", 100);
   set_skill("ghost-steps", 100);
   //雪蒼
   set_skill("snow-martial", 100);
   set_skill("snowforce", 100);
   set_skill("black-steps", 100);
   //隴山
   set("functions/kang_kee/level", 50);

   set_skill("lungshan", 100);
   set_skill("haoforce", 100);
   set_skill("henma-steps", 100);
   //道家
   set_skill("necromancy", 100);
   set_skill("gwhip", 100);
   set_skill("gforce", 100);
   set_skill("g-steps", 100);


   //因為是儒門的 所以先設成儒門武功...
   map_skill("force", "poetforce");
   map_skill("parry", "knowpen");
   map_skill("dodge", "winter-steps");
   map_skill("move", "winter-steps");
   map_skill("stabber", "knowpen");
   map_skill("plan", "god-plan");

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

   set("inquiry", ([
       "得意絕招"    :    @LONG
老師傅的得意絕招就是「儒門幻指」ㄚ, 當年成立(五儒生)之時
, 老師傅曾教了我一兩手。
LONG,
       "五儒生"      :    @LONG
當年老師傅因自己是武林四大高手之一, 因此想藉此來壯大儒門
, 特將我與其他四位師兄弟組成了五儒生, 各練就一身不同的武功。
LONG,
       "儒門"        :    @LONG
唉...為何總要我舊話重提呢...想當年老師傅待我不薄, 沒想到
老師傅竟會遭到不測, 致使他的(得意絕招)因此而失傳了, 我為了追
查殺死老師傅的兇手, 已經在此隱姓埋名了好幾年了, 無奈卻連一點
頭序也沒有...
LONG,
       "製作武器"    :    (: make_weapon :),
       "材料"        :    @LONG
上佳的材料, 首推江湖上極為難得的(宇內五禽), 製造武器的材
料只需要五禽身體的任何一部份, 再加上一(特殊的礦石)就可以了。
LONG,
       "特殊的礦石"  :    "所謂特殊的礦石就是指(宇內五珍)嘛。",
       "數目"        :    @LONG
明人不說暗話, 我也老了, 打算洗手不幹了, 若是你能付我黃金
百兩以上, 我就替你打造一把鋒利無批, 獨一無二的武器。
LONG,
       "宇內五禽"    :    @LONG
『宇內五禽』所指的就是五種珍禽異獸, 包括住在魔界中的四神
獸龍、鳳、龜、麒麟等四種, 另外還加上一隻行動如風、居無定所極
為難得一見的天山神鷹。
LONG,
       "宇內五珍"    :    @LONG
『宇內五珍』指的就是東海冰晶, 七彩玉石, 百鍊丹金, 萬年寒
冰, 及魔翡翠等五樣。
LONG,
   ]));

   set("chat_chance",20);
   set("chat_msg",({
      (: about_weapon :)
   }));
   set("chat_chance_combat",20);
   set("chat_msg_combat",({
      (: in_combat :)
   }));
   setup();

}

void init()
{
   add_action("do_select", "select");
   add_action("do_set_name", "set_name");
   add_action("do_vendor_list", "list");
}

int in_combat()
{
   object weapon, fall= this_object();
// 跟人家打架沒拿武器怎行...
   if( !present("m_weapon", this_object()))
   {
      init_weapon();
      weapon= new("/obj/m_weapon.c");            //不加 wield...

// 真是麻煩...武器抓不到 NPC 的設定....
      reload_weapon( weapon);

      weapon->move( fall);
      command("wield m_weapon");                          //這邊再 wield...
   }

   //仙劍
   (: perform_action,"sword.sha_kee" :);
   //金刀...
   (: perform_action,"blade.gold-dest" :);
   (: perform_action,"blade.fast-dest" :);
   //惡人...
   (: perform_action,"unarmed.evil-blade" :);
   //段家...
   (: perform_action,"stabber.handwriting" :);
   //儒門...
   (: perform_action,"stabber.movedown" :);
   (: perform_action,"plan.lock-link" :);
   (: perform_action,"plan.ghost" :);
   (: perform_action,"plan.fire" :);
   (: perform_action,"plan.fish" :);
   scholar_finger();                                    //來招儒門幻指吧..

   return 1;
}

int about_weapon()
{
   object weapon, fall= this_object();
   int chance= random( 10);

//如果身上有 m_weapon 則將他刪掉....表示剛剛有人跟他打過...
   if( weapon= present("m_weapon", this_object()))
      destruct( weapon);

   if( chance == 7)
      command("say 哈哈哈...這把新兵器打造的真是好ㄚ...");
   if( chance == 8)
      message_vision("風車:呼呼呼...鐵砧:ㄎ一ㄤ...ㄎ一ㄤ...ㄎ一ㄤ...\n", this_object());
   if( chance == 9)
      message_vision("炎熱的鐵工房燃燒著奇特火燄的大火...\n", this_object());

   return 1;
}

int init_weapon()
{
   object fall= this_object();

   switch( random( 10))
   {
      case 0:                                           //仙劍
         fall->map_skill("sword", "shasword");
         fall->map_skill("parry", "shasword");
         fall->map_skill("dodge", "sha-steps");
         fall->map_skill("move", "sha-steps");
         fall->map_skill("force", "shaforce");

         fall->set("weapon/type", "sword");
         fall->set("weapon/e_type", "sword");
         fall->set("weapon/c_type", "劍");
         fall->set("weapon/name", "獨孤九劍");
         break;
      case 1:                                           //京城
         fall->map_skill("dagger", "dragon-dagger");
         fall->map_skill("parry", "dragon-dagger");
         fall->map_skill("dodge", "chen-steps");
         fall->map_skill("move", "chen-steps");
         fall->map_skill("force", "oneforce");

         fall->set("weapon/type", "dagger");
         fall->set("weapon/e_type", "dagger");
         fall->set("weapon/c_type", "匕首");
         fall->set("weapon/name", "濺血匕");
         break;
      case 2:                                           //金刀
         fall->map_skill("blade", "fast-blade");
         fall->map_skill("parry", "gold-blade");
         fall->map_skill("dodge", "fly-steps");
         fall->map_skill("move", "fly-steps");
         fall->map_skill("force", "sixforce");

         fall->set("weapon/type", "blade");
         fall->set("weapon/e_type", "blade");
         fall->set("weapon/c_type", "刀");
         fall->set("weapon/name", "開山刀");
         break;
      case 3:                                           //段家
         fall->map_skill("unarmed", "six-fingers");
         fall->map_skill("stabber", "six-fingers");
         fall->map_skill("parry", "six-fingers");
         fall->map_skill("dodge", "linpo-steps");
         fall->map_skill("move", "linpo-steps");
         fall->map_skill("force", "sunforce");

         fall->set("weapon/type", "stabber");
         fall->set("weapon/e_type", "fan");
         fall->set("weapon/c_type", "扇");
         fall->set("weapon/name", "電風扇");
         break;
      case 4:                                           //惡人
         fall->map_skill("unarmed", "badstrike");
         fall->map_skill("parry", "badstrike");
         fall->map_skill("dodge", "ghost-steps");
         fall->map_skill("move", "ghost-steps");
         fall->map_skill("force", "badforce");

         fall->set("weapon/type", "unarmed");
         fall->set("weapon/e_type", "ring");
         fall->set("weapon/c_type", "指環");
         fall->set("weapon/name", "結婚鑽戒");
         break;
      case 5:                                           //雪蒼
         fall->map_skill("unarmed", "snow-martial");
         fall->map_skill("dodge", "black-steps");
         fall->map_skill("move", "black-steps");
         fall->map_skill("force", "snowforce");

         fall->set("weapon/type", "unarmed");
         fall->set("weapon/e_type", "armband");
         fall->set("weapon/c_type", "臂環");
         fall->set("weapon/name", "中央圓環");
         break;
      case 6:                                           //隴山
         fall->map_skill("unarmed", "lungshan");
         fall->map_skill("dodge", "henma-steps");
         fall->map_skill("move", "henma-steps");
         fall->map_skill("force", "haoforce");

         fall->set("weapon/type", "unarmed");
         fall->set("weapon/e_type", "armband");
         fall->set("weapon/c_type", "臂環");
         fall->set("weapon/name", "夏威夷花圈");
         break;
      case 7:                                           //儒門
      case 8:
      case 9:
         fall->set("weapon/type", "stabber");
         fall->set("weapon/e_type", "pen");
         fall->set("weapon/c_type", "筆");
         fall->set("weapon/name", "小蛋蛋專用筆");

         break;
   }
   fall->set("weapon/source1", "蛋殼");                 //ccc...
   fall->set("weapon/source2", "蛋黃");                 //hoho...
   fall->set("weapon/value", 100);

   return 1;
}

int scholar_finger()
{
   object me= this_object();
   object corpse, target, *enemy= me->query_enemy();
   string weakest;
   int i, enemy_num= sizeof( enemy);
   int gin, kee, sen;

   int literate, force_lv;
   for( i= 0; i< enemy_num; i++)
   {
      target= enemy[ i];
      gin= target->query("gin");
      kee= target->query("kee");
      sen= target->query("sen");

      literate= target->query_skill("literate");
      force_lv= target->query_skill("force");

      if( gin < kee && gin < sen)
         weakest= "gin";
      if( kee < gin && kee < sen)
         weakest= "kee";
      if( sen < gin && sen < kee)
         weakest= "sen";

      message_vision(@LONG
$N雙手一合, 口中念念有詞, 突然目光精光四射, 從$n身上電掃而過
                施展出儒門失傳已久獨步武林之

＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
＝＝＝＝＝＝＝＝＝＝＝＝＝『儒門幻指』＝＝＝＝＝＝＝＝＝＝＝＝＝＝
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
LONG, me, target);

      if( random( literate+ force_lv) < 150)
      {
         message_vision(@LONG
就在千鈞一髮的最後一刻, $N走差了氣, 致使儒門幻指打偏了,
打中路旁看戲的路人甲 + 路人乙 & 路人丙....
LONG, me, target);

         corpse= new("/obj/corpse");
         corpse->move( environment( target));
      }
      else
      {
         message_vision("
只見$N全身似乎是著了火似的, 周身燃起了陣陣的剛氣,
\n
手中的"+ me->query("weapon/name")+ "電光四射, 招招都射中了$n的周身大穴...
\n
", me, target);
         message_vision("\n看來$n已經受到嚴重的創傷, 已經快要不行了。\n", me, target);
      }

      target->add( weakest, -me->query_skill("stabber")/ 2);
   }
   return 1;
}

object reload_weapon( object weapon)
{
   object fall= this_object();
   string c_unit, wield_part, weapon_type= fall->query("weapon/e_type");

   if( weapon_type == "whip")
   {
      c_unit= "柄";
      wield_part= "手中";
   }
   else if( weapon_type == "pen")
   {
      c_unit= "隻";
      wield_part= "手中";
   }
   else if( weapon_type == "ring")
   {
      c_unit= "只";
      wield_part= "指上";
   }
   else if( weapon_type == "armband")
   {
      c_unit= "個";
      wield_part= "臂上";
   }
   else                                      // 剩下的為 劍 刀 匕首 拂塵 扇
   {
      c_unit= "把";
      wield_part= "手中";
   }

   weapon->set_name( fall->query("weapon/name"),({"special "+ fall->query("weapon/e_type"), fall->query("weapon/e_type"), "m_weapon"}) );
   weapon->init_sword( fall->query("weapon/value"));
   weapon->set("skill_type", fall->query("weapon/type"));
   if( fall->query("weapon/type") == "stabber" || fall->query("weapon/type") == "unarmed")
   {
      weapon->set("wield_msg", HIW"只見$N大喝一聲, 一道白光迅速由$N懷中竄出, \n在空中盤桓三圈後停在$N的"+wield_part+"化成一"+c_unit+"獨特的"+ fall->query("weapon/name")+"。\n"NOR);
weapon->set("unwield_msg", HIW"突然間$N的胸腹之間吸足了氣, 朝"+wield_part+"的$n輕輕一吹, 只見$n慢慢的化作一道光芒隱沒在$N的胸腹之間。\n"NOR);
   }
   else // if( c_unit == "把" || c_unit == "柄")// 指 劍 刀 匕首 拂塵...扇子不會出現
   {
      weapon->set("wield_msg", HIW"$N輕輕的將"+ fall->query("weapon/name")+"由背後抽出, 只見一道耀眼而詭異的光芒注入了$N身上。\n"NOR);
      weapon->set("unwield_msg", HIW"$N將手中的$n隨手往天上一丟, 只見它巧妙的落回了背後。\n"NOR);
   }
   return weapon;
}

int accept_fight( object ob)
{
   object weapon, fall= this_object();
   command("say 哈哈哈...太好了, 老夫正愁沒人能來試試我新打造的兵器呢...");
   command("say 那老夫就用它來與你過過招吧...小心了...");

   init_weapon();

   weapon= new("/obj/m_weapon.c");       //不加 wield...

// 真是麻煩...武器抓不到 NPC 的設定....
   weapon= reload_weapon( weapon);

   weapon->move( fall);
   command("wield m_weapon");                     //這邊再 wield...
   return 1;
}

int accept_kill(object ob)
{
   object fall= this_object();
   object weapon;
   command("say 想殺我...只怕你還沒這個份量...");

   init_weapon();

   fall->set("weapon/value", 200);                      //偷偷調高一點...
   fall->set("force_factor", 50);

   weapon= new("/obj/m_weapon.c");       //不加 wield...

// 真是麻煩...武器抓不到 NPC 的設定....
   reload_weapon( weapon);

   weapon->move( fall);
   command("wield m_weapon");                     //這邊再 wield...
   return 1;
}

string make_weapon()
{
   object me= this_player();
   if( present( "m_weapon", me) )
      return("老夫只幫人做一次武器, 老夫已經幫你作過了, 你請回吧。");
   me->set_temp("accept_obj", 1);
   return (@LONG
老夫不幫別人做武器已經很久了, 除非你能拿出百年難得一見
的(材料), 及一筆為數可觀的(數目), 否則免談。
LONG);
}

int do_set_name( string arg)
{
   object weapon;
   object me= this_player();
// 判斷是否允許命名...
   if( me->query_temp("allow_name") != 1)
   {
      command("? "+ me->query("id"));
      command("say 你要幹嘛ㄚ.....");
      return 1;
   }
// 是否有加參數...
   if( !arg)
   {
      command("say 為你的"+ me->query_temp("weapon_type")+"命名有這麼困難嗎? 快做決定吧。");
      return 1;
   }
// 將一些設定寫入 data
   arg = trans_color(arg);
   me->set("weapon/name", arg+NOR);
   me->set("weapon/source1", me->query_temp("weapon_source1"));
   me->set("weapon/source2", me->query_temp("weapon_source2"));
   me->set("weapon/c_type", me->query_temp("weapon_type"));


   switch( me->query_temp("weapon_type"))
   {
      case "劍":
      {
         me->set("weapon/type", "sword");
         me->set("weapon/e_type", "sword");
         me->set("weapon/c_type", "劍");
         break;
      }
      case "刀":
      {
         me->set("weapon/type", "blade");
         me->set("weapon/e_type", "blade");
         me->set("weapon/c_type", "刀");
         break;
      }
      case "扇":
      {
         me->set("weapon/type", "stabber");
         me->set("weapon/e_type", "fan");
         me->set("weapon/c_type", "扇");
         break;
      }
      case "筆":
      {
         me->set("weapon/type", "stabber");
         me->set("weapon/e_type", "pen");
         me->set("weapon/c_type", "筆");
         break;
      }
      case "指環":
      {
         me->set("weapon/type", "unarmed");
         me->set("weapon/e_type", "ring");
         me->set("weapon/c_type", "指環");
         break;
      }
      case "鞭":
      {  
         me->set("weapon/type", "whip");
         me->set("weapon/e_type", "whip");
         me->set("weapon/c_type", "鞭");
         break;
      }
      case "拂塵":
      {  
         me->set("weapon/type", "whip");
         me->set("weapon/e_type", "whip");
         me->set("weapon/c_type", "拂塵");
         break;
      }
      case "匕首":
      {
         me->set("weapon/type", "dagger");
         me->set("weapon/e_type", "dagger");
         me->set("weapon/c_type", "匕首");
         break;
      }
      case "弓":
      {
         me->set("weapon/type", "archery");
         me->set("weapon/e_type", "bow");
         me->set("weapon/c_type", "弓");
         break;
      }
   }

   new("/obj/m_weapon.c")->move( me);
   command("say 好了, 這把"+ me->query_temp("weapon_type")+ "已經製作完成了, 請收下吧。");
   message_vision("楚勝秋給了你一把"+ arg+ "\n", me);
// 將所有 temp 刪除...
   me->delete_temp("give_money");
   me->delete_temp("allow_name");
   me->delete_temp("weapon_source1");
   me->delete_temp("weapon_source2");
   me->delete_temp("weapon_type");
   me->delete_temp("allow_select");
   me->delete_temp("accept_obj");
   return 1;
}

int do_select( string arg)
{
   object me= this_player();
// 檢查是否允許選擇 武器型態
   if( !me->query_temp("allow_select") )
   {
      command("? "+ this_player()->query("id"));
      command("say 選什麼...誰說要讓你選了...");
      return 1;
   }
// 沒加參數...
   if( !arg)
   {
      command("say 老夫會製造的武器有 刀 扇 筆 劍 弓 指環 鞭 拂塵 及 匕首");
      command("say 快選擇(select)吧...");
      return 1;
   }
// 是否在設定型態中
   if( arg != "劍" && arg != "扇" && arg != "筆" && arg != "刀" && arg != "指環" && arg != "鞭" && arg != "拂塵" && arg != "匕首" && arg != "弓")
   {
      command("say 很抱歉, 老夫能力有限, 不會製作這種武器...");
      command("say 請重新選擇...");
      return 1;
   }

// ................
   me->set_temp("weapon_type", arg);
   command("say 要做"+ arg+"是吧! 好, 沒問題...");

   message_vision("只聽見楚勝秋在後院鍊鐵爐旁敲敲打打的聲音, \n不久就見他拿出了一把攝人氣魄的"+ arg+ "出來。\n", me);
   command("say 哈哈...真是一把好"+ arg+".....。");
   command("say 請為這把"+ arg+ "命名(set_name)吧。");
   me->set_temp("allow_name", 1);

   return 1;
}

int accept_object(object me, object obj)
{
   string obj_name= obj->query("name");
   string weapon_type= me->query_temp("weapon_type");
// 先判斷是否已經問過要 製作武器 了
   if( me->query_temp("accept_obj"))
   {
// 判斷是否宇內五禽
      if( obj_name == "真龜血晶" || obj_name == HIY"魔龍鱗"NOR)
      {
         command("pat "+getuid(me));
         command("say 太好了, 這是上佳的"+ obj_name+ "。");
// 是的話設定 temp weapon_source1, destruct( obj)...
         me->set_temp("weapon_source1", obj_name);
         destruct(obj);
// 判斷是否有給過五珍, 若無則 return...
         if( !me->query_temp("weapon_source2"))
         {
            command("say 快將『宇內五珍』拿給我, 好讓我幫你打造武器...");
            return 1;
         }
// 已給過 五珍 五禽 判斷是否有給錢...
         if( !me->query_temp("give_money"))
         {
            command("say 不過.........請先付款........");
            return 1;
         }
// 已給過 五珍 五禽 & 錢......要求選擇武器型態 set_temp("allow_select", 1)
         command("say 請選擇(select)你要的武器型態。");
         me->set_temp("allow_select", 1);
         return 1;
      }

// 判斷是否宇內五珍
      if( obj_name == "東海冰晶" || obj_name == "百煉丹金")
      {
         command("pat "+getuid(me));
         command("say 太好了, 這是上佳的"+ obj_name+ "。");
// 是的話設定 temp weapon_source2, desturct( obj)...
         me->set_temp("weapon_source2", obj_name);
         destruct(obj);
// 判斷是否有給過五禽, 若無則 return...
         if( !me->query_temp("weapon_source1"))
         {
            command("say 快將『宇內五珍』拿給我, 好讓我幫你打造武器...");
            return 1;
         }
// 已給過 五珍 五禽 判斷是否有給錢...
         if( !me->query_temp("give_money"))
         {
            command("say 不過.........請先付款........");
            return 1;
         }
// 已給過 五珍 五禽 & 錢......要求選擇武器型態 set_temp("allow_select", 1)
         command("say 請選擇(select)你要的武器型態。");
         me->set_temp("allow_select", 1);
         return 1;
      }

// 判斷是否給錢...
      if( obj_name == "黃金")
      {
// 判斷是否超過百金
         if( obj->value() < 1000000)
         {
            command("? "+ getuid(me));
            command("say 數目好像有點不對哦..., 請湊齊百金之後再來...");
            command("say 黃金數目只有"+ obj->value()/10000);
            obj->move( me);
            message_vision("楚勝秋將"+ obj->query("name")+ "還給了$N。\n", me);
            return 0;
         }
// 超過百金...set_temp("give_money", 1), set("weapon/value", gold/5)
         message_vision("只見楚勝秋將黃金拿起來咬了一咬。\n", me);
         command("say 好, 這果然是真的黃金...");
         me->set_temp("give_money", 1);
// 大於 500 gold
         if( obj->value()/ 10000 > 500)
            me->set("weapon/value", 100);
         else
            me->set("weapon/value", obj->value()/50000);

         destruct(obj);

// 檢查是否有給過 五禽
         if( !me->query_temp("weapon_source1"))
         {
            command("say 快將『宇內五禽』拿來吧, 好讓老夫趕快動工。");
            return 1;
         }
// 檢查是否有給過 五珍
         if( !me->query_temp("weapon_source2"))
         {
            command("say 快將『宇內五珍』拿來吧, 好讓老夫趕快動工。");
            return 1;
         }
// 已給過 五珍 五禽 & 錢......要求選擇武器型態 set_temp("allow_select", 1)
         command("say 請選擇(select)你要的武器型態。");
         me->set_temp("allow_select", 1);
         return 1;
      }
   }
// 尚未問過 製作武器
   else
   {
      command("? "+getuid(me));
      command("say 給我這種東西幹麻...");
      obj->move( me);
      message_vision("楚勝秋將"+ obj->query("name")+ "還給了$N。\n", me);
      return 1;
   }
}
