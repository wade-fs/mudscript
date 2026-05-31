//extra-kee.c
//調整為少林派專用版 by blazakira
//增加與佛法相關條件
//增加變化 使玩家可選擇是否使用進階加血模式
//分為兩種加血方式 第一種 普通加血 扣內力 成效低落
//第二種 含佛力 暫定潛力激發 會扣佛力最大值
#include <ansi.h>
int perform( object me )
{
	int fun,i,mforce,dhyana,j,k;
	mforce = me->query("max_force");
	fun=me->query("functions/vitality/level");
	dhyana = me->query("max_s_kee");
//	i = mforce * fun / 100 + fun * 15; //firghter 假設mforce=13000 >> 13000*100/100+100*15=14500
	i = mforce * fun / 130 + dhyana * fun / 5; //假設mforce=13000 >> 13000*100/130+300*20=16000
	j = mforce * fun / 130 * 0.85; //假設mforce=13000 >> 13000*100/130*0.85=8500
	k = mforce*1.9+dhyana*fun/50;
	me->set_temp("bonze/hpup/max_kee",me->query("max_kee")); //作為hp增加之暫存紀錄
	me->set_temp("bonze/hpup/max_gin",me->query("max_gin"));
	me->set_temp("bonze/hpup/max_sen",me->query("max_sen"));
	if( me->query("eff_kee")!=me->query("max_kee"))
		return notify_fail( "你的傷勢導致無法使用伐毛洗髓！\n" );
	if( me->query("kee")!=me->query("eff_kee"))
		return notify_fail( "你的傷勢導致無法使用伐毛洗髓！\n" );
	if( me->query("class")!="bonze" )
		return notify_fail( "非少林派無法使用！\n" );
	if( !me->query("bonze/force/shenzuforce",1) )
		return notify_fail("要用伐毛洗髓得先學會神足經才行。\n");
	if( (string)me->query_skill_mapped("force")!= "saulinforce" )
		return notify_fail("伐毛洗髓要以少林內功\做基礎。\n");
	if( me->query("env/force") != "神足經" && me->query("env/force") != "shenzuforce")
		return notify_fail("伐毛洗髓要用神足經來啟動。\n");
	if( me->query("max_force") < 2000 ) //因為少林並非以force為主的門派 故而降低條件
		return notify_fail( "你的內力不足，不足以伐毛洗髓！\n" );
	if( me->query_temp("hpup") == 1 ) //使用中並降低傷害作為代價
		return notify_fail( "你已經使用伐毛洗髓了！\n" );
//	if( me->query("force") < mforce*1.9+dhyana*fun/50 ) //降低要求 並增加佛法相關條件 //假設為13000*1.9+300*2=25300
	if( me->query("force") < k ) //降低要求 並增加佛法相關條件 //假設為13000*1.9+300*2=25300
		return notify_fail( "你的內力不足以支撐伐毛洗髓！\n" );
	if (me->query("max_s_kee") < 50) //因為使用伐毛洗髓會扣佛法最大值 故而限制最低條件
		return notify_fail("你的佛法領悟不足，無法聚神使出伐毛洗髓！\n");
	if( me->is_fighting() ) { me->start_busy(1); }
	message_vision( RED"$N憑著高深的佛法修為融會貫通神足經上的經文，驅使體內內勁伐毛洗髓！\n"NOR, me ); 
	if( !me->query("env/潛能激發",1) ) {
		me->add("force", -(j*100/fun) );
		me->add("max_gin",500+fun*2); //讓人看得見技能的差異性
		me->add("max_sen",500+fun*2); //最高數值為增加500+200 所以就不顯示了
		me->add("max_kee",j);
		me->add("eff_kee",j);
		me->add("kee",j);
		me->add("s_kee",-150); //增加與佛法的相關性
		if(wizardp(me)) {
			write(HBBLU+HIG"【巫師專用測試資料】目前 force 消耗為 "+(j*100/fun)+"\n"NOR,me); //測試資訊
			write(HBBLU+HIG"【巫師專用測試資料】目前 kee 增加數值為 "+i+"\n"NOR,me); //測試
		}
	}
	else {
//		me->add("force", -(i*11/10) );
		me->add("force", -k );
		me->add("max_gin",dhyana*10);
		me->add("max_sen",dhyana*10);
		me->add("max_kee",i);
		me->add("eff_kee",i);
		me->add("kee",i);
		me->add("max_s_kee",-1); //增加與佛法的相關性
		if(wizardp(me)) {
			write(HBBLU+HIG"【巫師專用測試資料】目前 force 消耗為 "+k+"\n"NOR,me); //測試
			write(HBBLU+HIG"【巫師專用測試資料】目前 gin & sen 增加數值為 "+dhyana*10+" kee 增加數值為"+i+"\n"NOR,me); //測試
		}
	}

	me->set_temp("hpup",1);
	call_out( "remove_effect", 120+fun,me);
	return 1;
}

void remove_effect( object me )
{
	int fun;
	if(!me) return;
	fun = me->query("functions/vitality/level");
	if(me->query_temp("hpup")) {
		me->set("max_kee",me->query_temp("bonze/hpup/max_kee"));
		me->set("max_gin",me->query_temp("bonze/hpup/max_gin"));
		me->set("max_sen",me->query_temp("bonze/hpup/max_sen"));
		me->set("eff_kee",me->query("max_kee"));
		me->set("eff_gin",me->query("max_gin"));
		me->set("eff_sen",me->query("max_sen"));
		me->delete_temp("hpup");
		tell_object( me, HIR"你體內的內勁漸漸恢復了。\n"NOR );
		if( fun < 100 ) {	me->function_improved( "vitality", random(fun)*2 + random(fun) ); }
		me->delete_temp("bonze/hpup"); //刪除作為hp增加之暫存紀錄
		return;
	}
}
