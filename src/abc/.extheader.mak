abc.d: ../../include/gvAbcCmd.h ../../include/gvAbcMgr.h ../../include/gvAbcNtk.h ../../include/gvAigMgr.h ../../include/gvCnf.h 
../../include/gvAbcCmd.h: gvAbcCmd.h
	@rm -f ../../include/gvAbcCmd.h
	@ln -fs ../src/abc/gvAbcCmd.h ../../include/gvAbcCmd.h
../../include/gvAbcMgr.h: gvAbcMgr.h
	@rm -f ../../include/gvAbcMgr.h
	@ln -fs ../src/abc/gvAbcMgr.h ../../include/gvAbcMgr.h
../../include/gvAbcNtk.h: gvAbcNtk.h
	@rm -f ../../include/gvAbcNtk.h
	@ln -fs ../src/abc/gvAbcNtk.h ../../include/gvAbcNtk.h
../../include/gvAigMgr.h: gvAigMgr.h
	@rm -f ../../include/gvAigMgr.h
	@ln -fs ../src/abc/gvAigMgr.h ../../include/gvAigMgr.h
../../include/gvCnf.h: gvCnf.h
	@rm -f ../../include/gvCnf.h
	@ln -fs ../src/abc/gvCnf.h ../../include/gvCnf.h
