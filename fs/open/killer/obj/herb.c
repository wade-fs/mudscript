inherit ITEM;
void create()
{
set_name("富士山秘草",({"herb"}));
set_weight(20);
if( clonep() )
set_default_object(__FILE__);
else {
  set("long","一株不甚起眼的雜草，令你不禁想丟掉他。\n");
  set("unit","盒");
  set("no_sell",1);
  set("食物", ([
                        "剩" : 1,       // 可以吃幾口
                        "供應": 10,     // 每一口填飽肚子的量
          ]) );
}
setup();
}
