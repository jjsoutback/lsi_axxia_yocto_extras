# support for fmboot
# drops a copy of linux.img in tmp/deploy/images

do_compile_append (){
        make -C source/arch/arm/boot/fmboot \
		DTC=$PWD/scripts/dtc/dtc \
		ZIMAGE=$PWD/arch/arm/boot/zImage
        cp source/arch/arm/boot/fmboot/linux.img .
        make -C source/arch/arm/boot/fmboot clean
}

do_deploy_append(){
	cp ${B}/linux.img ${DEPLOYDIR}/
}

