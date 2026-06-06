inherit ITEM;

void create()
{
        set_name( "古文書",({"papyrus"}));
        set_weight(400);
        if( clonep() )
          set_default_object(__FILE__);
        else {
          set("unit", "本");
          set("long","
塵封的書皮，泛黃的紙頁，一眼便可想見其年代之久遠。
古文書上寫著：
ΩΘ○⊙☆■◇....●★▽ΓΞζη￡....ψ◆....
你看了半天，卻連一個字也看不懂....。
非得找個人翻譯不行 。\n");
}
        setup();
}
