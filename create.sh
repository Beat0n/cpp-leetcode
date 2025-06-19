seq=$1

dir="src/excise/ex$seq"

# 创建目录，如果目录已存在则不会报错
mkdir -p "${dir}"

# 创建文件
touch "${dir}/impl_${seq}.hh"
touch "${dir}/test_${seq}.cc"

echo '' >> "${dir}/impl_${seq}.hh"
echo '#include "../common.hh"' >> "${dir}/impl_${seq}.hh"
echo '' >> "${dir}/impl_${seq}.hh"

printf "#include \"impl_%s.hh\"\n" "${seq}" >> "${dir}/test_${seq}.cc"
printf '\nint main() {\n\n}' >> "${dir}/test_${seq}.cc"

printf "target(\"ex%s\")\n" "${seq}" >> "xmake.lua"
echo '    set_kind("binary")' >> "xmake.lua"
echo '    set_languages("c++20")' >> "xmake.lua"
printf "    add_files(\"%s/*.cc\")\n" "${dir}" >> "xmake.lua"
echo '' >> "xmake.lua"