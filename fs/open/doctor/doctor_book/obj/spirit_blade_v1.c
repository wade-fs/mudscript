#include <ansi.h>
inherit ITEM;

object control(object me,object base_mob,object);

void create()
{
  set_name(RED + "≦怨靈纏繞≧"+HBYEL+HIW + "雙" + HIC + "界" + HIR + "刀" + NOR, ({ "spirit blade","sb" }) ); //增添惡靈附身之類的敘述在名字之前 //因此當解除惡靈附身時便取消該敘述 同土靈珠
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value",0);
    set("unit", "把");
    set("long", "這是一把透過不斷的吸收(increase 生之力)魂魄和鮮血可以不斷的提升品質的邪刀。\n"+
      "可藉由某種" + HIG + "儀式" + HIW + "抵抗惡靈" + NOR + "，傳聞某位住在墳場的人比較清楚。\n\n");
    set("no_auc",1);
    set("no_sell",1);
    set("no_sec",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_steal",1);
    set("no_save",1);
    set("no_get",1);
    set("no_give",1);
  }
  setup();
}

void init()
{
  object me;
  me = environment(this_object());
  me->set_temp("spirit_curse",1); //標註狀態 惡靈纏身
  if( !userp(me) )
    me->apply_condition("spirit_curse",0);
  else
    me->apply_condition("spirit_curse",10); //沒有狀態傷害時 就啟動惡靈纏身狀態傷害
  add_action("do_apply","apply");
  add_action("do_amass","increase");
  add_action("do_give","gi");
  add_action("do_give","giv");
  add_action("do_give","give");
}
/*
void curse_on() //改用condition來控制
{
  object ob=this_object(),me=environment(ob);
  int k;
  if( !me || !environment(me) ) return ;
  k=5;
  if( me->query_temp("curse/resist")==1 ) k=7; //值等於3時 已經算解除 所以不列入
  else if( me->query_temp("curse/resist")==2 ) k=10;
  if( me->query_temp("spirit_curse") ) {
//varargs int receive_wound(string type, int damage, object who) //object who作為傳入參數 用在last_damage_from
    message_vision(HIR + "惡靈纏身\n" + NOR,me);
    me->start_busy(random(3)+2);
    me->receive_damage("gin", (int)(me->query("max_gin")/k),ob );
    me->receive_wound ("gin", (int)(me->query("max_gin")/k),ob );
    me->receive_damage("kee", (int)(me->query("max_kee")/k),ob );
    me->receive_wound ("kee", (int)(me->query("max_kee")/k),ob );
    me->receive_damage("sen", (int)(me->query("max_sen")/k),ob );
    me->receive_wound ("sen", (int)(me->query("max_sen")/k),ob );
    COMBAT_D->report_status(me);
  }
  return;
}
*/
int do_give(string arg)
{
  string target,item;
  object who,ob=this_object(),me=environment(ob);
  if( !arg )
    return 0;
  if( sscanf(arg,"%s to %s",item,target)==2 || //保留這個判斷是為了指定target參數的存在
      sscanf(arg,"%s %s",target,item)==2 ); //需保留此分號 否則會與下方衝突
  else return notify_fail("你要給誰什麼東西﹖\n");
  if( !objectp(who = present(target,environment(me))) || !living(who) ) //使用這個判斷是為了確定與目標同一間房間
    return notify_fail("這裡沒有這個人。\n");
  if( item==query("id") && who->query("id")=="master death" )
  {
    if( me->query_temp("spirit_curse") ) {
      me->delete_temp("spirit_curse");
    }
    if( me->query_condition("spirit_curse") ) { //有惡靈狀態時 就刪除惡靈狀態傷害
      me->apply_condition("spirit_curse",0);
    }
    me->delete("quest/doctor_book/temp/"); //刪除暫存mark
    set("no_give",0); //關閉本物件的no_give 以便於在下方的return 0中 接著使用原指令give的判斷跟動作==交給對方
  }
  return 0;
}

int do_apply(string arg)
{
  string ob1,ob2;
  object pill,ob=this_object(),me=environment(ob);

  if( !arg )
    return 0;
  if( !me->query_temp("spirit_curse") ) //既然解除了就不用往下判斷
    return 0;
  if( sscanf(arg, "%s to %s",ob1,ob2) != 2 )
    return notify_fail("你想塗抹些什麼？\n(apply something to weapon.)\n");
/*
lo 說 (下午 09:47):
pill->add_amount(-1)
*/
  pill=present(ob1,me);
  if( ob2 == "blade" ) {
    if( ob1 == "sky pill" && !me->query_temp("curse/sky_pill") && pill ) {
      message_vision("眾惡靈發出小小聲地痛苦呻吟，似乎在抗議$N的動作。\n",me); //ok
      pill->add_amount(-1);
      me->set_temp("curse/sky_pill",1);
      me->add_temp("curse/resist",1);
    }
    else if( ob1 == "gen pill" && !me->query_temp("curse/gen_pill") && pill ) {
      message_vision("眾惡靈發出小小聲地痛苦呻吟，似乎在抗議$N的動作。\n",me); //ok
      pill->add_amount(-1);
      me->set_temp("curse/gen_pill",1);
      me->add_temp("curse/resist",1);
    }
    else if( ob1 == "human pill" && !me->query_temp("curse/human_pill") && pill ) {
      message_vision("眾惡靈發出小小聲地痛苦呻吟，似乎在抗議$N的動作。\n",me); //ok
      pill->add_amount(-1);
      me->set_temp("curse/human_pill",1);
      me->add_temp("curse/resist",1);
    }
    if( me->query_temp("curse/sky_pill") && 
        me->query_temp("curse/gen_pill") &&
        me->query_temp("curse/human_pill") ) {
//解除詛咒
      set_name(HBYEL+HIW + "雙" + HIC + "界" + HIR + "刀" + NOR, ({ "spirit blade","sb" }) );
      me->delete_temp("spirit_curse");
      message_vision("眾惡靈不約而同發出一陣呻吟，惡狠狠地瞪著$N之後收縮回刀中。\n",me); //end
      call_out("delay_time", 60*16, me);
    }
    return 1;
  }
  return 0;
}

int do_amass(string arg)
{
  string ob1,ob2;
  string npcs;
  object ob=this_object(),me=environment(ob),item1,item2;
  mixed *inv;
  int i,k;

  inv = all_inventory(environment(me));
  if( !arg )
    return 0;
//  if(me->is_fighting()) //由於海皇打不死 所以
//    return notify_fail("收集生之力的動作只能在非戰鬥中使用。\n");
  if( me->is_busy() )
    return notify_fail("收集儀式準備中。\n");

//  if(sscanf(arg, "%s for %s",ob1,ob2) != 2)
//    return notify_fail("指令格式錯誤。\n");
  if( arg != "energy of spirit" ) //因為海皇打不死 因此會被直接destruct() 所以不使用corpse for spirit
    return notify_fail("指令格式錯誤。\n(increase energy of spirit)\n");
  me->start_busy(random(3)+2);
  delete("message_on"); //刪除海皇造成訊息衝突的額外判別紀錄
  for (i=0; i<sizeof(inv); i++) { //使用迴圈的方式來判斷房間內的物件 亦可參考上方的do_give內容來指定房間裡的物件
    if( !inv[i]->is_corpse() && inv[i]->query("id") != "dragon-god" ) continue; //不是屍體也並非是海皇時就跳過
    if( inv[i]->query("id") == "dragon-god" ) inv[i]->set("victim_name","海皇"); //既然對象是海皇之後 就設屍體name吧 為了統一判斷
    switch( inv[i]->query("victim_name") ) { //判斷房間的物件 //屍體的原始名稱紀錄
      case "海皇" :
        break;
      case "蛇郎君" :
        npcs="/open/quests/snake/npc/master_snake.c";
        break;
      case "火龍王" :
        npcs="/open/fire-hole/npc/fire-dragon.c";
        break;
      case "焚天魔王" :
        npcs="/open/mogi/castle/npc/fire-king.c";
        break;
      case "死靈骨魔" :
        npcs="/open/ghost-hole/npc/ghost-king.c";
        break;
      default :
        message_vision("這附近沒有生之力。\n",me); //判斷並非目標屍體時
        return 1;
        break;
    }
    //這敘述的累積傷害判定放在npc本身die()函數裡面 意即玩家不使用本指令就看不到 但是仍有紀錄 不過不會觸發下列的判定 也就沒有quest後續
    //海皇是打不死的 所以沒有npcs存在 也沒有 victim_name
    if( npcs && inv[i]->query("id") != "dragon-god" ) //npcs 存在時 表示目標除了海皇之外都變成了屍體=非戰鬥時才會發生 && me->is_fighting()<<不能使用
      message_vision("在$N持之以恆地給予"+inv[i]->query("victim_name")+"傷害之後，終於從"+inv[i]->query("victim_name")+"的身上積聚了生之力。\n",me); //這是基於這五隻npc不會同時出現在同一間房間而使用的敘述
    else if( inv[i]->query("id") == "dragon-god" && inv[i]->query("name") =="海皇" && me->is_fighting() ) {
      message_vision("在$N持之以恆地給予"+inv[i]->query("name")+"傷害之後，終於從"+inv[i]->query("name")+"的身上積聚了生之力。\n",me);
      set("message_on",1);
    }
    else if( inv[i]->query("id") == "dragon-god" && inv[i]->query("name") =="海皇" && !me->is_fighting() ) //雙重判定 稍微嚴謹一點
      message_vision("只是看著海皇，可是無法從他身上收集到生之力喔。\n",me);
    if( me->query_temp("not_robot")) k=5; //有太極之力時 提高機率
    else k=100;
    if( me->query_temp("spiritup") && random(k)==2 ) //加上機率? 收割如果沒成功會變成疆屍(此殭屍放在這if的else裡面判定)
    { //累積傷害成功後 機率轉換成功
      item2=new("/open/doctor/doctor_book/obj/scrap2");
      if( me->query_temp("spiritup")=="master snake" && item1=present("star soul splinters",me) )
      {
        item2->set("sort","星");
      }
      else if( me->query_temp("spiritup")=="death ghost king" && item1=present("lin soul splinters",me) )
      {
        item2->set("sort","麟");
      }
      else if( me->query_temp("spiritup")=="fire king" && item1=present("jing soul splinters",me) )
      {
        item2->set("sort","井");
      }
      else if( me->query_temp("spiritup")=="dragon king" && item1=present("kui soul splinters",me) )
      {
        item2->set("sort","奎");
      }
      else if( me->query_temp("spiritup")=="dragon-god" && item1=present("spica soul splinters",me) )
      {
        item2->set("sort","角");
      }
      else continue; //if( !item1 ) continue; //沒有持有的關鍵道具時 就跳出if的迴圈
      tell_object(me,GRN + "忽然間你身上的靈魂碎片" + NOR+item1->query("name")+GRN + "光芒大作，你從懷裡將它掏出一看，原來它藉由你收集的生之力變成了充滿生機的靈魂碎片。\n" + NOR);
      destruct(present(item1->query("id"),me)); //or destruct(item1)?
      if( inv[i]->query("id") != "dragon-god" ) //排除海皇 其他則刪除物件
        destruct(inv[i]);
      else
        inv[i]->delete_temp("record_damage/"+me->query("id")); //已經交換成功之後 刪除海皇身上紀錄的累積傷害
      item2->move(me);
      me->delete_temp("spiritup"); //放在此處表示 使用指令的同時 需同時具備 1.目標屍體 2.打死之前已累積傷害 並取得足夠傷害之證明temp 3.機率獲得該證明 才算成功 否則均刪除並要求重打 不使用就可以多次打敗之後 成功機率上升(這點是累積傷害的不確定性
      return 1;
    }
    else if(me->query_temp("spiritup") && me->query_temp("spiritup") != "dragon-god" && me->query("quest/doctor_book/temp/call_vampire/"+me->query_temp("spiritup")) < time() )
    {
      object base_mob,target,mob;
      seteuid(getuid());
      base_mob = target = new (npcs);
      control(ob,base_mob,target);
    }
  } //end for
  if( !query("message_on") )
    if( !npcs && sizeof(inv)>1 ) //情況 如果不是 目標屍體出現 或是打不死的海皇存在時=npcs不存在 且 房間裡物件包含自己>1
    { //這段有用? 似乎前面的swith擋住了
      tell_object(me,"似乎積聚生之力的時候尚未來臨吧。\n");
    }
    else if( sizeof(inv)==1 ) { //房間裡物件只有自己
      tell_object(me,"你眼前有東西存在？\n");
    }
    else if( !npcs )
      tell_object(me,"你試著從目標身上積聚生之力，但是效果不大。\n");
  return 1;
}

int query_autoload()
{
  return 1;
}

int delay_time(object who)
{
  if( who )
  {
    who->delete_temp("curse"); //reset參數 重新開始
    set_name(RED + "≦怨靈纏繞≧"+HBYEL+HIW + "雙" + HIC + "界" + HIR + "刀" + NOR, ({ "spirit blade","sb" }) );
    who->set_temp("spirit_curse",1);
  }
  return 1;
}

object control(object ob,object base_mob,object target)
{
//  object *all_control_mob;
  object mob,me=environment(ob);
  if( !me || !environment(me) ) return ;

//  if(me->query_temp("control_z"))
//     all_control_mob = me->query_temp("control_z") - ({ 0 });

  seteuid(getuid());
  mob = new ("/daemon/class/taoist/necromancy/npc/mob.c");
  if( sizeof(base_mob->query_skills()) )
  {
    foreach(string skill,int level in base_mob->query_skills() )
    {
      mob->set_skill(skill,level);
    }
  }
  if( sizeof(base_mob->query_skill_map()) )
  {
    foreach(string skill,string level in base_mob->query_skill_map() )
    {
      mob->map_skill(skill,level);
    }
  }
  foreach(string key,mixed value in base_mob->query_entire_dbase() )
  {
    mob->set(key,value);
  }
  mob->delete("chat_msg_combat");
  mob->delete("family/privs");
/*
  if(!sizeof(all_control_mob))
    all_control_mob = allocate(0);
  
  all_control_mob += ({ mob });
  me->set_temp("control_z",all_control_mob);
*/
  mob->set_name(mob->query("name")+ "的屍體",({mob->query("id") + "'s vampire","vampire"}));
  mob->setup();
  mob->move(environment(me));
  all_inventory(target)->move(mob);
  all_inventory(mob)->wield();
  all_inventory(mob)->wear();
  mob->set("long",mob->query("long") + "\n但現在卻異變成殭屍。\n");
  mob->delete("chat_msg");
  mob->delete("inquiry");
  mob->set("horse",1);
  mob->set("no_recruit",1);
  mob->set_leader(me);
  mob->set("master",me);
  mob->set("env/sid",1);
  destruct(target);
  message_vision(HIY + "\n\n\t由於$N收集生之力的過程中有了點瑕疵導致儀式失敗，接著" + NOR+mob->query("name")+HIY + "\n\t雙眼冒出綠光悠然的站了起來。\n\n\n" + NOR,me);
  message_vision(""+mob->query("name")+"決定開始跟隨$N一起行動。\n",me);
  me->set("quest/doctor_book/temp/call_vampire/"+me->query_temp("spiritup"),time() + 60*15); //避免重複呼叫導致無限的殭屍
  mob->do_command("kill "+me->query("id"));
  return ;
}
