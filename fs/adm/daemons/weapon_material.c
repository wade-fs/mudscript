//設計 by Neverend 2001/09/28
//判斷武器的材質和鋒利度
#include <combat.h> 
#include <ansi.h>

void weapon_material(object me,object target)
{
	string wo,oo,wn,on;
	int wm,om,ws,os,wd,od,qq;

	object ob=target->query_temp("weapon");
	object weapon=me->query_temp("weapon");

	if( !weapon || !ob )
	return;
//如果未給定材質和鋒利度，由以下來給定所以都未給定的
//狀態下，武器的初始值給定在300 的值，若能夠拿最好的
//武器，是可以直接砍斷對方的武器。

	if( !weapon->query("material") )
	weapon->set("material","iron");
	if( !ob->query("material") )
	ob->set("material","iron");
	if( !weapon->query("sharp") )
	weapon->set("sharp",6);
	if( !ob->query("sharp") )
	ob->set("sharp",6);
//以下取得原來的名稱
	if( !weapon->query("bname") )
	{
	wn = weapon->query("name");
	weapon->set("bname",wn);
	}
	if( !ob->query("bname") )
	{
	on = ob->query("name");
	ob->set("bname",on);
	}
//以下是武器的材質    
	wo = weapon->query("material");
	oo = ob->query("material");
//以下是武器的鋒利度
	ws = weapon->query("sharp");
	os = ob->query("sharp");

	switch(wo)
	{
	case "crimsonsteel": wm=100;  break;
	case "blacksteel":   wm=90;   break;
	case "gem":          wm=80;   break;
	case "gold":         wm=70;   break;
	case "silver":       wm=60;   break;
	case "steel":        wm=50;   break;
	case "copper":       wm=40;   break;
	case "iron":         wm=30;   break;
	case "wood":         wm=25;   break;
	case "bone":         wm=20;   break;
	case "leather":      wm=15;   break;
	case "fur":          wm=10;   break;
	case "cloth":        wm=5;    break;
	default:             wm=1;    break;
	}

	switch(oo)
	{
	case "crimsonsteel": om=100;  break;
	case "blacksteel":   om=90;   break;
	case "gem":          om=80;   break;
	case "gold":         om=70;   break;
	case "silver":       om=60;   break;
	case "steel":        om=50;   break;
	case "copper":       om=40;   break;
	case "iron":         om=30;   break;
	case "wood":         om=25;   break;
	case "bone":         om=20;   break;
	case "leather":      om=15;   break;
	case "fur":          om=10;   break;
	case "cloth":        om=5;    break;
	default:             om=1;    break;
	}
//武器的等級用(材質)*(鋒利度)來定義
	wd = wm * ws;
	if( wd > 1000 ) wd=1000;
	od = om * os;
	if( od > 1000 ) od=1000;
	qq = random( wd-od );

//強制設定只要差距大於850，就直接砍斷對方的武器，機率設在1/2左右
	if( random(10) > 5 && (wd - od > 850) )
	{
	message_vision(HIC + "$N的" + NOR+weapon->name()+HIC + "「唰」地一聲﹐把$n" + HIC + "的" + NOR+ob->name()+HIC + "削成兩段!!\n" + NOR,me,target);
	ob->unequip();
	ob->move(environment(target));
	ob->set("name", "(斷毀兩段)" + ob->query("name"));
	ob->set("value", 1);
	ob->set("weapon_prop/damage",0);
	target->reset_action();
	}else{
//在這個範圍內，因為武器等級差距甚大，所以會有較大的機會傷害對方武器
//差距愈大，對方武器愈有機會受損 (0.67 - 0.3 )之間
	  if( qq > 280 && (wd-od < 850 && wd-od > 400) )
	  {
	  ob->unequip();
	  message_vision(HIR + "$N的" + NOR+weapon->name()+HIR + "把$n" + HIR + "的" + NOR+ob->name()+HIR + "重重的砍出了一個嚴重的缺口!!\n" + NOR,me,target);
//	  message_vision("$N"+wd+"，$n"+od+"。\n",me,target);
	  ob->add("bad",2);
	    if( ob->query("bad") >= 11 )
	    ob->set("name", "(極盡崩碎)" + ob->query("bname"));
	    if( ob->query("bad") == 10 )
	    ob->set("name", "(嚴重損壞)" + ob->query("bname"));
	    if( ob->query("bad") == 9 )
	    ob->set("name", "(殘破不堪)" + ob->query("bname"));
	    if( ob->query("bad") == 8 )
	    ob->set("name", "(不堪使用)" + ob->query("bname"));
	    if( ob->query("bad") == 7 )
	    ob->set("name", "(崩碎多處)" + ob->query("bname"));
	    if( ob->query("bad") == 6 )
	    ob->set("name", "(尚堪使用)" + ob->query("bname"));
	    if( ob->query("bad") == 5 )
	    ob->set("name", "(多處裂痕)" + ob->query("bname"));
	    if( ob->query("bad") == 4 )
	    ob->set("name", "(小有裂痕)" + ob->query("bname"));
	    if( ob->query("bad") == 3 )
	    ob->set("name", "(輕微裂痕)" + ob->query("bname"));
	    if( ob->query("bad") == 2 )
	    ob->set("name", "(輕微缺口)" + ob->query("bname"));
	    if( ob->query("bad") == 1 )
	    ob->set("name", "(輕微受損)" + ob->query("bname"));
	    if( ob->query("weapon_prop/damage") > 10 || ob->query("bad") < 12 )
	    {
	    ob->add("weapon_prop/damage",-10);
	    ob->wield();
	    }else{
	      message_vision(RED + "$n" + RED + "的"+ob->name()+RED + "再也承受不住攻擊完全斷毀了!!\n" + NOR,me,target);
	    ob->move(environment(target));
	    ob->set("name", "(完全斷毀)" + ob->query("bname"));
	    ob->set("value", 1);
	    ob->set("weapon_prop/damage",0);
	    target->reset_action();
	    }
	  }else{
//武器等級差距較小，但仍然能傷害對方的武器
//差距愈大，對方武器愈有機會受損 (0.625 - 0.25)之間
	    if( qq > 150 && (wd-od < 400 && wd-od > 200) )
	    {
	    ob->unequip();
	    message_vision(HIY + "$N" + HIY + "的" + NOR+weapon->name()+HIY + "把$n" + HIY + "的" + NOR+ob->name()+HIY + "輕輕的砍出了一個小缺口!!\n" + NOR,me,target);
	    ob->add("bad",1);
	      if( ob->query("bad") >= 11 )
	      ob->set("name", "(極盡崩碎)" + ob->query("bname"));
	      if( ob->query("bad") == 10 )
	      ob->set("name", "(嚴重損壞)" + ob->query("bname"));
	      if( ob->query("bad") == 9 )
	      ob->set("name", "(殘破不堪)" + ob->query("bname"));
	      if( ob->query("bad") == 8 )
	      ob->set("name", "(不堪使用)" + ob->query("bname"));
	      if( ob->query("bad") == 7 )
	      ob->set("name", "(崩碎多處)" + ob->query("bname"));
	      if( ob->query("bad") == 6 )
	      ob->set("name", "(尚堪使用)" + ob->query("bname"));
	      if( ob->query("bad") == 5 )
	      ob->set("name", "(多處裂痕)" + ob->query("bname"));
	      if( ob->query("bad") == 4 )
	      ob->set("name", "(小有裂痕)" + ob->query("bname"));
	      if( ob->query("bad") == 3 )
	      ob->set("name", "(輕微裂痕)" + ob->query("bname"));
	      if( ob->query("bad") == 2 )
	      ob->set("name", "(輕微缺口)" + ob->query("bname"));
	      if( ob->query("bad") == 1 )
	      ob->set("name", "(輕微受損)" + ob->query("bname"));
	      if( ob->query("weapon_prop/damage") > 5 || ob->query("bad") < 12 )
	      {
	      ob->add("weapon_prop/damage",-5);
	      ob->wield();
	      }else{
	      message_vision(RED + "$n" + RED + "的"+ob->name()+RED + "再也承受不住攻擊碎裂斷毀了!!\n" + NOR,me,target);
	      ob->move(environment(target));
	      ob->set("name", "(碎裂斷毀)" + ob->query("bname"));
	      ob->set("value", 1);
	      ob->set("weapon_prop/damage",0);
	      target->reset_action();
	      }
	    }else{
//以下武器等級相當，所以不再以傷害對方武器
	      if( qq > 75 && (wd-od < 200 && wd-od > 100) )
	      {
	      message_vision(HIG + "$n" + HIG + "只覺得手中" + NOR+ob->name()+HIG + "被" + NOR+weapon->name()+HIG + "一震﹐險些脫手飛出!!\n" + NOR,me,target);
		  }else{
		    if( qq > 25 && (wd-od < 100 && wd-od > 50) )
		    {
	        message_vision(HIW + "$N" + HIW + "的" + NOR+weapon->name()+HIW + "和$n" + HIW + "的" + NOR+ob->name()+HIW + "相擊﹐冒出點點的火星。\n" + NOR,me,target);
	        }else{
	          if( random(10) > 5 && (wd == od) )
	          {
	          message_vision(HIM + "$N" + HIM + "的" + NOR+weapon->name()+HIM + "和$n" + HIM + "的" + NOR+ob->name()+HIM + "相擊﹐發出響亮清脆的聲音。\n" + NOR,me,target);
	          }
	        }
	      }
	    }
	  }
	}
}
