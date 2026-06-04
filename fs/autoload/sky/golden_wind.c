//調整使用者的判定以減少玩家離線 或者持有者不存在時會出錯 並修正敘述錯誤 再增加last_damage_from的設定 by blazakira 2011/4/10
//調整型態為弓時 不能裝箭的問題 by blazakira 2011/6/15
//改變wield形式為int wield() (參考殺意魔戒) by blazakira 2011/7/24

#include <weapon.h>
#include <ansi.h>
#include <combat.h>

inherit SWORD;

void create()
{
  seteuid(getuid());
  set_name(HIM + "金風舞夢旋" + NOR,({ "golden-wind" }));
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "把");
    set("long", "天靈地界中，具有最神秘力量且破壞力最強大的武器，武器上並鑲上了紅藍黃三色晶珠。\n(可使用help golden-wind來查詢詳細說明。)\n");
    set("value",100000);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_sec",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_steal",1);
    set("no_save",1);
//    set("no_get",1);
    set("red_yellow",1);
    set("type", 1);
//    set("change",1);
    set("rigidity",20);
    set("sharp",9);
    set("material", "crimsonsteel");
    set("need_exp",5000000);
  }
  init_sword(150);
  setup();
}

void init()
{
  object ob=this_object(),me=environment(ob);
  if( !ob || !me ) return;
  if( !ob->query("boss") ) ob->set("boss",me->query("id"));
  add_action("do_change","change");
  add_action("change1","setwp");
  add_action("do_check","checkpower");
  add_action("do_help","help");
}

int wield()
{
  object ob=this_object(),me=environment(ob);
  int ret=::wield();
  string str="";
//  if(me->query("combat_exp") < 5000000) return notify_fail(HIC + "你的江湖歷練並不足以駕馭這樣的靈動神器!!\n" + NOR); //裝備武器之前可以做額外的限制
//  set("wield_msg",HIM + "$n" + HIM + "散出一股異樣的光芒，流散在$N" + HIM + "的周身!!\n" + NOR);
//  str+=ob->query("wield_msg");
  if( !query("original_name") ) { //為不指定武器型態時 也就是基礎狀態下
    delete("wield_msg");
    if( query_heart_beat() )
      set_heart_beat(0);
    return ret;
  }
  else if( ob->query("change") == 1 ) 
  {
    str+=HIW + "$N" + HIW + "拿起$n" + HIW + "，$N" + HIW + "覺得自己的財富之路似乎又接近了一些!!\n" + NOR;
  }
  else if( ob->query("change") == 2 )
  {
    str+=HIW + "$N" + HIW + "拿起$n" + HIW + "，$N" + HIW + "覺得自己的潛藏能量似乎又提升了一些!!\n" + NOR;
  }
  else if( ob->query("change") == 3 )
  {
    str+=HIW + "$N" + HIW + "拿起$n" + HIW + "，$N" + HIW + "覺得自己的武學之道似乎又變強了一些!!\n" + NOR;
  }
  else { //有指定武器型態(original_name存在時) 但是不想使用武器用途時
    delete("wield_msg");
    if( query_heart_beat() )
      set_heart_beat(0);
    return ret;
  }
  set("wield_msg",str+HIM + "$n" + HIM + "散出一股異樣的光芒，流散在$N" + HIM + "的周身!!\n" + NOR); //指定用途時的通用方式
  if( query("equipped") && !query_heart_beat() ) {
    set_heart_beat(1);
  }
  return ret;
}

int unequip()
{
  object ob=this_object(),me=environment(ob);
  int ret = ::unequip();
  set("unwield_msg","灌注在$n的內力中斷，$n流散在$N周身的光芒漸漸消散，回歸為最初的型態" + HIW + "「" + HIM + "金風舞夢旋" + HIW + "」" + NOR + "了!!\n$N不捨的將$n小心的收起放好。\n");
//  set_heart_beat(0); //交由心跳函數來判斷
  if( query("original_name") && !ob->query("change") ) { //為指定武器型態時 但是沒有指定用途時
    delete("unwield_msg");
    return ret;
  }
  else if( !query("original_name") && !ob->query("change") ) { //不指定型態與不指定用途時的預設
    delete("unwield_msg");
    return ret;
  }
//其他 即指指定武器用途時(ob->query("change"))
//  message_vision("$N不捨的將$n小心的收起放好。\n",me,ob);
//  message_vision("灌注在$n的內力中斷，漸漸回歸為最初的型態" + HIW + "「" + HIM + "金風舞夢旋" + HIW + "」" + NOR + "了!!\n",me,ob);
//  ob->set_name( HIM + "金風舞夢旋" + NOR,({"golden-wind"}) );
/* //暫時不取消好了
  if( query("arrow/id") ) {
    ob->delete("can_hold");
    ob->delete("arrow");
  }
*/
  return ret;
}

int do_change(string str) //武器型態
{
  object ob=this_object(),me=environment(ob);
  switch(str)
  {
    case "unarmed":
      set("skill_type", "unarmed");
      set_name( "爪" + NOR,({"money-claw"}));
      ob->set("original_name","爪" + NOR);
      ob->change2(); //改名字 但是第一次時為!ob->query("change")的情況
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    case "sword":
      set("skill_type", "sword");
      set_name( "劍" + NOR,({"money-sword"}));
      ob->set("original_name","劍" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    case "archery":
      set("skill_type", "archery");
      set_name( "弓" + NOR,({"money-bow"}));
      ob->set("original_name","弓" + NOR);
      //直接套用inherit BOW的內容 by blazakira
      if( !query("arrow/id") ) {
        set("can_hold",1);
        // 初始化....把裝備的箭設成id = none ,amount = 0
        set("arrow/id","none");
        set("arrow/amount",0);
        set("arrow/name","空的");
      }
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      return 1;
      break;    
    case "blade":
      set("skill_type", "blade");
      set_name( "刀" + NOR,({"money-blade"}));
      ob->set("original_name","刀" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    case "dagger":
      set("skill_type", "dagger");
      set_name( "刃" + NOR,({"money-dagger"}));
      ob->set("original_name","刃" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    case "throwing":
      set("skill_type", "throwing");
      set_name( "翼" + NOR,({"money-wing"}));
      ob->set("original_name","翼" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;      
    case "whip":
      set("skill_type", "whip");
      set_name( "鍊" + NOR,({"money-chain"}));
      ob->set("original_name","鍊" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    case "needle":
      set("skill_type", "stabber");
      set_name( "針" + NOR,({"money-needle"}) );
      ob->set("original_name","針" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    case "fan":
      set("skill_type", "stabber");
      set_name( "扇" + NOR,({"money-fan"}) );
      ob->set("original_name","扇" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    case "staff":
      set("skill_type", "staff");
      set_name( "鎚" + NOR,({"money-star"}) );
      ob->set("original_name","鎚" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    case "lance":
      set("skill_type", "lance");
      set_name( "槍" + NOR,({"money-lance"}) );
      ob->set("original_name","槍" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    case "axe":
      set("skill_type", "axe");
      set_name( "斧" + NOR,({"money-axe"}) );
      ob->set("original_name","斧" + NOR);
      ob->change2();
      message_vision("強烈的光芒過後，凝聚在$N手中的赫然是一把$n。\n",me,ob);
      break;
    default :
      message_vision("$n怎麼樣就是感應不到$N的呼應!!\n",me,ob);
  }
/* //暫時不取消好了
  if( query("arrow/id") ) { //其他狀態時 則取消箭的設定
    message_vision("在光芒的包圍下裝備的箭消失了！\n",me,ob);
    ob->delete("can_hold");
    ob->delete("arrow");
  }
*/
  return 1;
}

int change1(string str) //武器效果
{
  object ob=this_object(),me=environment(ob);
  if( !str ) return notify_fail("請選擇你想轉換的狀態!!\n");
  if( !ob->query("original_name") ) return notify_fail("請先轉換你想要的武器型態再來變化狀態。\n");

  if( str == "搖錢" || str == "聚能" || str == "狂邪" )
  {
    if( str == "搖錢" )
    {
      if( ob->query("change") == 1 )
      {
        tell_object(me,ob->query("name")+"已經是" + HIC + "搖錢" + NOR + "狀態了！\n");
        return 1;
      } else {
        ob->set("change",1);
        me->set_temp("money_change",1);
        message_vision(HIW + "$N" + HIW + "灌注一股內力至藍色的晶珠之中，轉瞬間$n" + HIW + "已漸漸變化為搖錢狀態了。\n" + NOR,me,ob);
        ob->change2();
        if(!query_heart_beat() && query("equipped") ) //如果穿上武器時 也能轉換型態 所以取消轉換型態時會脫下武器的問題 //但是心跳問題??
          set_heart_beat(1); //改為 如果拿起武器時轉換型態就直接給予心跳功能
      }
    }
    if( str == "聚能" )
    {
      if( ob->query("change") == 2 )
      {
        tell_object(me,ob->query("name")+"已經是" + HIY + "聚能" + NOR + "狀態了！\n");
        return 1;
      } else {
        if( me->query("weapon/change2") == 1 )
        {
          ob->set("change",2);
          me->set_temp("money_change",2);
          message_vision(HIW + "$N" + HIW + "灌注一股內力至黃色的晶珠之中，轉瞬間$n" + HIW + "已漸漸變化為聚能狀態了。\n" + NOR,me,ob);
          ob->change2();
          if(!query_heart_beat() && query("equipped") )
            set_heart_beat(1); //改為 如果拿起武器時轉換型態就直接給予心跳功能
        } else {
          message_vision("$N還無法領悟這種型態變化的奧秘。\n" + NOR,me,ob);
          return 1;
        }
      }
    }
    if( str == "狂邪" )
    {
      if( ob->query("change") == 3 )
      {
        tell_object(me,ob->query("name")+"已經是" + HIR + "狂邪" + NOR + "狀態了！\n");
        return 1;
      } else {
        if( me->query("weapon/change3") == 1 )
        {
          ob->set("change",3);
          me->set_temp("money_change",3);
          message_vision(HIW + "$N" + HIW + "灌注一股內力至紅色的晶珠之中，轉瞬間$n" + HIW + "已漸漸變化為狂邪狀態了。\n" + NOR,me,ob);
          ob->change2();
          if(!query_heart_beat() && query("equipped") )
            set_heart_beat(1); //改為 如果拿起武器時轉換型態就直接給予心跳功能
        } else {
          message_vision("$N還無法領悟這種型態變化的奧秘。\n" + NOR,me,ob);
        return 1;
        }
      }
    }
  } else {
    message_vision(HIW + "請選擇一個正確的型態(「搖錢」或「聚能」或「狂邪」)\n" + NOR,me);
  }
  return 1;
}

int change2() //更改武器名稱
{
  object ob=this_object();
  if( !ob->query("change") && !ob->query("original_name") ) //沒有指定用途且沒有指定型態 則使用預設名稱
    ob->set_name( HIM + "金風舞夢旋" + NOR,({"golden-wind"}) );
  else if( ob->query("change") == 1 )
  {
    ob->set("name",HIC + "搖" + HIB + "錢" + HIC + "樹" + HIB + "靈" + HIC+ob->query("original_name"));
  }
  else if( ob->query("change") == 2 )
  {
    ob->set("name",HIY + "聚" + NOR+YEL + "能" + HIY + "樹" + NOR+YEL + "靈" + HIY+ob->query("original_name"));
  }
  else if( ob->query("change") == 3 )
  {
    ob->set("name",HIR + "狂" + NOR+RED + "邪" + HIR + "樹" + NOR+RED + "靈" + HIR+ob->query("original_name"));
  }
  else //改變型態 但是未指定用途時 就給予預設名稱
  {
    ob->set("name",HIC + "搖" + HIB + "錢" + HIC + "樹" + HIB + "靈" + HIC+ob->query("original_name"));
  }
  return 1;
}

int do_check(string str) //檢查狂邪力
{
  object ob=this_object(),me=environment(ob);
  tell_object(me,ob->query("name")+HIW + "已經吸取了【" + HIM+me->query("weapon/money_point")+HIW + "】點狂邪力。\n" + NOR);
  return 1;
}

int delt(object ob)
{
  ob=this_object();
  message_vision(ob->query("name")+HIW + "消耗的能量，已漸漸回歸至能量充足狀態。\n" + NOR,ob);
  ob->delete("money_crazy");
  return 1;
}

void heart_beat()
{
  object c1,c2,c3,c4,c5,c6,c7,*enemy,m1,m2,m3,m4,m5;
  object ob=this_object(),me=environment(ob);
  int i,j,k,l,kar,spi,a1,a2,a3,a4,a5,fun,mp;
  j=random(-1);
/*
  c1=new("/obj/money/coin.c");
  c2=new("/obj/money/silver.c");
  c3=new("/obj/money/gold.c");
  c4=new("/obj/money/cash.c");
  c5=new("/obj/money/cash.c");
  c5->set_amount(10);
  c6=new("/obj/money/cash.c");
  c6->set_amount(50);
  c7=new("/obj/money/diamond.c");
*/
  if ( !me || !objectp(me) || !query("equipped") ) //本裝備沒裝備在身上時就停止心跳 //於是之後的判斷可省略query("equipped")
  {
    if( ob->query("original_name") && ob->query("change") ) { //如果脫下裝備時有指定型態且已經有指定效果時才會恢復
      ob->delete("change"); //不指定效果就依照高攻武器吧 也就不會進入此判斷
      ob->delete("original_name");
      ob->change2();
    }
    me->delete_temp("money_change");
    set_heart_beat(0);
    return;
  }

//第三個武器效果 吸取身上的狂邪力
  if( ob->query("change") == 3 && me->query_condition("money_crazy") < 1 && me->query("weapon/money_point") > 500 )
  {
    if( me->query_temp("money_change") == 3 )
    {
      if( me->query("weapon/money_point") >= 500 && me->query("weapon/money_point") < 1000)
      {
        message_vision(ob->query("name")+HIC + "發出一陣微鳴想吸取$N" + HIC + "身上的" + HIR + "狂邪力" + HIC + "能量，卻已漸漸無從著力。\n" + NOR,me);
        me->add("weapon/money_point",-500);
        me->apply_condition("money_crazy",me->query_condition("money_crazy")+10);
      } else {
        message_vision(ob->query("name")+HIC + "發出一陣微鳴吸取了$N" + HIC + "身上的" + HIR + "狂邪力" + HIC + "能量後，不斷輕微地顫抖著。\n" + NOR,me);
        me->add("weapon/money_point",-500);
        me->apply_condition("money_crazy",me->query_condition("money_crazy")+10);
      }
    }
  }

//第一個武器效果
  if( me->is_fighting() && ob->query("change") == 1 )
  {
    enemy=me->query_enemy();
    if(!enemy) return ;
    if( environment(me) == environment(enemy[i]) )
    {
      i=random(sizeof(enemy));
      kar=me->query_kar();
      spi=me->query_spi();
      m1=present("coin_money",enemy[i]);
      m2=present("silver_money",enemy[i]);
      m3=present("gold_money",enemy[i]);
      m4=present("cash_money",enemy[i]);
      if( m1 ) a1=m1->query_amount();
      if( m2 ) a2=m2->query_amount();
      if( m3 ) a3=m3->query_amount();
      if( m4 ) a4=m4->query_amount();
      if( kar > 40 ) kar=40;
      if( spi > 40 ) spi=40;
      if( userp(enemy[i]) ){
        k=1500;
      } else {
        k=500;
      }
      if( random(kar*spi) > k )
      {
        if( a1 >= 1 && random(2) == 1 )
        {
          a1=a1-1;
          m1->set_amount(a1);
          message_vision(ob->query("name")+HIC + "吸取了$n" + HIC + "身上的一文錢並轉化為二文錢回歸到" + HIW + "$N" + HIC + "。\n" + NOR,me,enemy[i]);
          c1=new("/obj/money/coin.c");
          c1->set_amount(2);
          c1->move(me);
        }
        if( a2 >= 1 && random(2) == 1 )
        {
          a2=a2-1;
          m2->set_amount(a2);
          message_vision(ob->query("name")+HIC + "吸取了$n" + HIC + "身上的一兩銀子並轉化為二兩銀子回歸到" + HIW + "$N" + HIC + "。\n" + NOR,me,enemy[i]);
          c2=new("/obj/money/silver.c");
          c2->set_amount(2);
          c2->move(me);
        }
        if( a3 >= 1 && random(2) == 1 )
        {
          a3=a3-1;
          m3->set_amount(a3);
          message_vision(ob->query("name")+HIC + "吸取了$n" + HIC + "身上的一兩金子並轉化為二兩金子回歸到" + HIW + "$N" + HIC + "。\n" + NOR,me,enemy[i]);
          c3=new("/obj/money/gold.c");
          c3->set_amount(2);
          c3->move(me);
        }
        if( a4 >= 1 && random(2) == 1 )
        {
          a4=a4-1;
          m4->set_amount(a4);
          message_vision(ob->query("name")+HIC + "吸取了$n" + HIC + "身上的一張萬兩銀票並轉化為二張萬兩銀票回歸到" + HIW + "$N" + HIC + "。\n" + NOR,me,enemy[i]);
          c4=new("/obj/money/cash.c");
          c4->set_amount(2);
          c4->move(me);
        }
      }
    }
    switch(j)
    {
      case 8750..9250:
        message_vision("忽然由$n裏掉出了一文錢，結結實實的打在$N身上!!\n",me,ob);
        c1=new("/obj/money/coin.c");
        c1->move(me);
        break;
      case 9251..9500:
        message_vision("忽然由$n裏掉出了一兩銀子，結結實實的打在$N身上!!\n",me,ob);
        c2=new("/obj/money/silver.c");
        c2->move(me);
        break;
      case 9501..9750:
        message_vision(HIY + "忽然由$n" + HIY + "裏掉出了一兩金子，結結實實的打在$N身上!!\n" + NOR,me,ob);
        c3=new("/obj/money/gold.c");
        c3->move(me);
        break;
      case 9751..9985:
        message_vision(HIW + "忽然由$n" + HIW + "裏掉出了一張萬兩銀票，結結實實的打在$N身上!!\n" + NOR,me,ob);
        c4=new("/obj/money/cash.c");
        c4->move(me);
        break;
      case 9986..9992:
        message_vision(HIW + "忽然由$n" + HIW + "裏掉出了十張萬兩銀票，結結實實的打在$N身上!!\n" + NOR,me,ob);
        c5=new("/obj/money/cash.c");
        c5->set_amount(10);
        c5->move(me);
        break;
      case 9993..9998:
        message_vision(HIC + "忽然由$n" + HIG + "裏掉出了五十張萬兩銀票，結結實實的打在$N身上!!\n" + NOR,me,ob);
        c6=new("/obj/money/cash.c");
        c6->set_amount(50);
        c6->move(me);
        break;
      case 9999..10000:
        message_vision(HIC + "忽然由$n" + HIC + "裏掉出了一粒鑽石，結結實實的打在$N身上!!\n" + NOR,me,ob);
        c7=new("/obj/money/diamond.c");
        c7->move(me);
        break;
    }
  }

//第二個武器效果
  if( me->is_fighting() && ob->query("change") == 2 )
  {
    enemy=me->query_enemy();
    if(!enemy) return ;
    if( environment(me) == environment(enemy[i]) )
    {
      i=random(sizeof(enemy));
      kar=me->query_kar();
      spi=me->query_spi();
      m1=present("coin_money",enemy[i]);
      m2=present("silver_money",enemy[i]);
      m3=present("gold_money",enemy[i]);
      m4=present("cash_money",enemy[i]);
      if( m1 ) a1=m1->query_amount();
      if( m2 ) a2=m2->query_amount();
      if( m3 ) a3=m3->query_amount();
      if( m4 ) a4=m4->query_amount();
      if( kar > 40 ) kar=40;
      if( spi > 40 ) spi=40;
      if( userp(enemy[i]) ) {
        k=1500;
      } else {
        k=500;
      }
      if( random(kar*spi) > k )
      {
        if( a1 >= 1 && random(2) == 1 )
        {
          a1=a1-1;
          m1->set_amount(a1);
          message_vision(ob->query("name")+HIY + "吸取了$n" + HIY + "身上的一文錢並轉化為一點能量回歸到" + HIW + "$N" + HIY + "。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",1);
        }
        if( a2 >= 1 && random(2) == 1 )
        {
          a2=a2-1;
          m2->set_amount(a2);
          message_vision(ob->query("name")+HIY + "吸取了$n" + HIY + "身上的一兩銀子並轉化為二點能量回歸到" + HIW + "$N" + HIY + "。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",2);
        }
        if( a3 >= 1 && random(2) == 1 )
        {
          a3=a3-1;
          m3->set_amount(a3);
          message_vision(ob->query("name")+HIY + "吸取了$n" + HIY + "身上的一兩金子並轉化為十點能量回歸到" + HIW + "$N" + HIY + "。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",5);
        }
        if( a4 >= 1 && random(2) == 1 )
        {
          a4=a4-1;
          m4->set_amount(a4);
          message_vision(ob->query("name")+HIY + "吸取了$n" + HIY + "身上的一張萬兩銀票並轉化為五十點能量回歸到" + HIW + "$N" + HIY + "。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",50);
        }
      }
    }
  }

//第三個武器效果 me->query("env/狂邪") == "YES"
  if( me->is_fighting() && query("equipped") && ob->query("change") == 3 && me->query("env/狂邪") == "YES" )
  {
    enemy=me->query_enemy();
    if(!enemy) return ;
    if( me->query("env/狂邪") != "YES" ) return ;
    if( ob->query("money_crazy") ) return ;
    if( random(me->query_spi()*2) > 35 ) return ;
    if( environment(me) == environment(enemy[i]) )
    {
      i=random(sizeof(enemy));
      m1=present("coin_money",me);
      m2=present("silver_money",me);
      m3=present("gold_money",me);
      m4=present("cash_money",me);
      m5=present("diamond_money",me);
      fun=me->query("functions/money_crazy/level");
      mp=me->query("weapon/money_point");
      if( m1 ) a1=m1->query_amount();
      if( m2 ) a2=m2->query_amount();
      if( m3 ) a3=m3->query_amount();
      if( m4 ) a4=m4->query_amount();
      if( m5 ) a5=m5->query_amount();
      if( fun < 15 )
      {
        if( a1 >= 1 && mp > fun  )
        {
          a1=a1-1;
          m1->set_amount(a1);
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一文錢轉化成一點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",-fun);
          enemy[i]->receive_damage("kee",fun*10,me);//damage(10-100)
          COMBAT_D->report_status(enemy[i]);
        } else {
          tell_object(me,"你身上的錢不足夠"+ob->query("name")+"感召。\n");
        return ;
        }
      }
      if( fun > 15 && fun <= 30 && mp > (fun*3*2) )
      {
        if( a1 >= 3 )
        {
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一文錢轉化成一點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<3;l++ )
          {
            a1=a1-1;
            m1->set_amount(a1);
            me->add("weapon/money_point",-2*fun);
            enemy[i]->receive_damage("kee",fun*15,me);//damage(450-900)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的錢不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 30 && fun <= 45 && mp > (fun*5*3) )
      {
        if( a1 >= 5 )
        {
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一文錢轉化成一點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<5;l++ )
          {
            a1=a1-1;
            m1->set_amount(a1);
            me->add("weapon/money_point",-3*fun);
            enemy[i]->receive_damage("kee",fun*20,me);//damage(2000-3000)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的錢不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 45 && fun <= 60 && mp > (fun*3*4) )
      {
        if( a2 >= 3 )
        {
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一兩銀子轉化成十點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<3;l++ )
          {
            a2=a2-1;
            m2->set_amount(a2);
            me->add("weapon/money_point",-4*fun);
            enemy[i]->receive_damage("kee",fun*40,me);//damage(3600-4800)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的銀子不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 60 && fun <= 75 && mp > (fun*5*5) )
      {
        if( a2 >= 5 )
        {
          for( l=0;l<5;l++ )
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一兩銀子轉化成十點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          {
            a2=a2-1;
            m2->set_amount(a2);
            me->add("weapon/money_point",-5*fun);
            enemy[i]->receive_damage("kee",fun*45,me);//damage(9000-11250)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的銀子不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 75 && fun <= 90 && mp > (fun*7*6) )
      {
        if( a2 >= 7 )
        {
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一兩銀子轉化成十點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<7;l++ )
          {
            a2=a2-1;
            m2->set_amount(a2);
            me->add("weapon/money_point",-6*fun);
            enemy[i]->receive_damage("kee",fun*50,me);//damage(17500-21000)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的銀子不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 90 && fun <= 105 && mp > (fun*5*7) )
      {
        if( a3 >= 5 )
        {
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一兩金子轉化成百點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<5;l++ )
          {
            a3=a3-1;
            m3->set_amount(a3);
            me->add("weapon/money_point",-7*fun);
            enemy[i]->receive_damage("kee",fun*70,me);//damage(21000-24500)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的金子不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 105 && fun <= 120 && mp > (fun*7*8) )
      {
        if( a3 >= 7 )
        {
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一兩金子轉化成百點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<7;l++ )
          {
            a3=a3-1;
            m3->set_amount(a3);
            me->add("weapon/money_point",-8*fun);
            enemy[i]->receive_damage("kee",fun*75,me);//damage(36750-42000)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的金子不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 120 && fun <= 135 && mp > (fun*9*9) )
      {
        if( a3 >= 9 )
        {
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一兩金子轉化成百點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<9;l++ )
          {
            a3=a3-1;
            m3->set_amount(a3);
            me->add("weapon/money_point",-9*fun);
            enemy[i]->receive_damage("kee",fun*80,me);//damage(57600-64800)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的金子不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 135 && fun <= 150  && mp > (fun*7*10) )
      {
        if( a4 >= 7 )
        {
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一張萬兩銀票轉化成千點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<7;l++ )
          {
            a4=a4-1;
            m4->set_amount(a4);
            me->add("weapon/money_point",-10*fun);
            enemy[i]->receive_damage("kee",fun*105,me);//damage(66150-73500)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的萬兩銀票不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 150 && fun <= 165 && mp > (fun*9*11) )
      {
        if( a4 >= 9 )
        {
          for( l=0;l<9;l++ )
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一張萬兩銀票轉化成千點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          {
            a4=a4-1;
            m4->set_amount(a4);
            me->add("weapon/money_point",-11*fun);
            enemy[i]->receive_damage("kee",fun*110,me);//damage(99000-108900)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的萬兩銀票不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 165 && fun <= 180 && mp > (fun*11*12) )
      {
        if( a4 >= 11 )
        {
          for( l=0;l<11;l++ )
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一張萬兩銀票轉化成千點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          {
            a4=a4-1;
            m4->set_amount(a4);
            me->add("weapon/money_point",-12*fun);
            enemy[i]->receive_damage("kee",fun*115,me);//damage(140415-151800)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的萬兩銀票不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 180 && fun <= 190  && mp > (fun*13*13) )
      {
        if( a4 >= 13 )
        {
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一張萬兩銀票轉化成千點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<13;l++ )
          {
            a4=a4-1;
            m4->set_amount(a4);
            me->add("weapon/money_point",-13*fun);
            enemy[i]->receive_damage("kee",fun*120,me);//damage(188760-202800)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的萬兩銀票不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      if( fun > 190 && mp > (fun*13*14) )
      {
        if( a5 >= 1 )
        {
          a5=a5-1;
          m5->set_amount(a5);
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的一粒鑽石轉化成萬點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          for( l=0;l<13;l++ )
          {
            me->add("weapon/money_point",-14*fun);
            enemy[i]->receive_damage("kee",fun*125,me);//damage(212875-......)
            COMBAT_D->report_status(enemy[i]);
          }
        } else {
          tell_object(me,"你身上的鑽石不足夠"+ob->query("name")+"感召。\n");
          return ;
        }
      }
      ob->set("money_crazy",1);
      call_out("delt",fun*3,ob);
    }
  }

//第三個武器效果 me->query("env/狂邪") == "ON"
  if( me->is_fighting() && query("equipped") && ob->query("change") == 3 && me->query("env/狂邪") == "ON" )
  {
    enemy=me->query_enemy();
    if(!enemy) return ;
    if( me->query("env/狂邪") != "ON" ) return ;
    if( ob->query("money_crazy") ) return ;
    if( random(me->query_spi()*2) > 35 ) return ;
    if( environment(me) == environment(enemy[i]) )
    {
      i=random(sizeof(enemy));
      m1=present("coin_money",me);
      m2=present("silver_money",me);
      m3=present("gold_money",me);
      m4=present("cash_money",me);
      m5=present("diamond_money",me);
      fun=me->query("functions/money_crazy/level");
      mp=me->query("weapon/money_point");
      if( m1 ) a1=m1->query_amount();
      if( m2 ) a2=m2->query_amount();
      if( m3 ) a3=m3->query_amount();
      if( m4 ) a4=m4->query_amount();
      if( m5 ) a5=m5->query_amount();
      if( fun < 15 )
      {
        if( a1 >= 1 && mp > fun*10 )
        {
          a1=a1-1;
          m1->set_amount(a1);
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的" + NOR + "一文錢" + HIR + "轉化成一點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",-fun*10);
          enemy[i]->receive_damage("kee",fun*10,me);//damage max(15*10)
          COMBAT_D->report_status(enemy[i]);
        }
      }
      if( fun >= 15 && fun < 45 )
      {
        if( a2 >= 1 && mp > fun*10 )
        {
          a2=a2-1;
          m2->set_amount(a2);
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的" + NOR + "一兩銀子" + HIR + "轉化成數十點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",-fun*10);
          enemy[i]->receive_damage("kee",fun*10+random(501),me);//damage max(45*10+500)
          COMBAT_D->report_status(enemy[i]);
        }
      }
      if( fun >= 45 && fun < 90 )
      {
        if( a3 >= 1 && mp > fun*10  )
        {
          a3=a3-1;
          m3->set_amount(a3);
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的" + HIY + "一兩金子" + HIR + "轉化成數百點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",-fun*10);
          enemy[i]->receive_damage("kee",fun*5+random(501),me);
          enemy[i]->receive_wound("kee",fun*5+random(501),me);//damage max(90*10+1000)
          COMBAT_D->report_status(enemy[i]);
        }
      }
      if( fun >= 90 && fun < 150 )
      {
        if( a4 >= 1 && mp > fun*10  )
        {
          a4=a4-1;
          m1->set_amount(a5);
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的" + NOR + "一張萬兩銀票" + HIR + "轉化成數華點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",-fun*10);
          enemy[i]->receive_damage("kee",fun*5+random(1501),me);
          enemy[i]->receive_wound("kee",fun*5+random(1501),me);//damage max(150*10+3000)
          COMBAT_D->report_status(enemy[i]);
        }
      }
      if( fun >= 150 )
      {
        if( a5 >= 1 && mp > fun*10  )
        {
          a5=a5-1;
          m5->set_amount(a5);
          message_vision(ob->query("name")+HIR + "感召了$N" + HIR + "身上的" + HIW + "一粒鑽石" + NOR + "轉化成數萬點光能朝" + HIW + "$n" + HIR + "激射。\n" + NOR,me,enemy[i]);
          me->add("weapon/money_point",-fun*10);
          enemy[i]->receive_wound("kee",fun*10+random(5001),me);//damage max(lv*10+5000)
          COMBAT_D->report_status(enemy[i]);
        }
      }
      ob->set("money_crazy",1);
      call_out("delt",10,ob);
    }
  }
  return;
}

int query_autoload()
{
  return 1;
}

int do_help(string str)
{ //既然有人關閉憑空變出金錢 那或許是會了調整fs的金錢型態 故而調整說明 by blazakira
  if (str!="golden-wind") return 0;

  write(@Help

        「金風舞飛璇」

        相傳天靈地界中擁有最強攻擊力的武器，共有三種
        不同的型態轉變，分別為：
        搖錢樹靈劍（武器類型）：
        武器顏色呈現藍色狀態，掌控其能量的是武器身上
        的藍色晶珠。是能吸取對手身上的金錢再轉化為二
        倍的量回歸至武器的使用者身上。
        聚能樹靈劍（武器類型）：
        武器顏色呈現黃色狀態，掌控其能量的是武器身上
        的黃色晶珠。在此狀態下，會將對手身上的金錢吸
        取並轉化為「狂邪力」儲存起來。
        狂邪樹靈劍（武器類型）：
        武器顏色呈現紅色狀態，掌控其能量的是武器身上
        的紅色晶珠。此一狀態下會發動狂邪靈力的產生，
        並增加使用者本身的「狂邪靈勁」。每次發動攻擊
        皆會吸取使用者身上的金錢並輔以狂邪力產生的能
        量攻擊對手。

        使用方式：
        武器變化類型：  change
        武器變化型態：  setwp (搖錢、聚能、狂邪)
        武器能量查詢：  checkpower
        武器攻擊發動：  set 狂邪 YES    (暴力攻擊型)
                        set 狂邪 ON     (一般攻擊型)

Help
);
  return 1;
}
