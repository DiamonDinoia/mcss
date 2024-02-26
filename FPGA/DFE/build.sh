#!/bin/bash -e

[ -z "$MAXPOWERDIR" ] && echo "Need to set MAXPOWERDIR" && exit 1;

#delete old build.xml file
rm -f build.xml
#build build.xml file for application

cat > build.xml << EOF
<?xml version="1.0" encoding="UTF-8"?>
<project name ="MCSS_DFE" default="all" basedir=".">
	<taskdef name="maxjcompiler" classname="org.eclipse.jdt.core.ant.taskdef.MaxjTask" classpath="$MAXCOMPILERDIR/lib/ecj.jar"/>
	<target name="all" depends="build"/>
	<target name="build">
		<delete dir="bin"/>
		<mkdir dir="bin"/>
		<copy includeemptydirs="false" todir="bin">
			<fileset dir="src" excludes="**/*.uad, **/*.ucd, **/*.uld, **/*.upd, **/*.udd, **/*.uod, **/*.usd, **/*.utd, **/*.uud, **/*.odd, **/*.ead, **/*.ecd, **/*.eld, **/*.epd, **/*.edd, **/*.eod, **/*.esd, **/*.etd, **/*.eud, **/*.urd*.uml, **/*.ecore, **/*.launch, **/*.java, **/*.maxj, **/package.html"/>
		</copy>
		<maxjcompiler srcdir="src" destdir="bin" debug="true" failonerror="true" debuglevel="lines,vars,source" source="1.8" target="1.8">
			<classpath>
				<pathelement path="$MAXCOMPILERDIR/lib/MaxCompiler.jar"/>
				<pathelement path="$MAXCOMPILERDIR/lib/Max5Platform.jar"/>
				<pathelement path="$MAXPOWERDIR/lib/MaxPower.jar"/>			
				<pathelement path="/usr/share/java/junit4.jar:/usr/share/java/junit.jar"/>
			</classpath>
		</maxjcompiler>
	</target>
	<target name="clean">
		<delete dir="bin"/>
	</target>
</project>
EOF

export APPDIR=.
export MAXAPPPKG=uk.ac.imperial.mcss;
export MAXJVMMEM=20000
export JUNIT=/usr/share/java/junit4.jar:/usr/share/java/junit.jar
export HAMCREST=$MAXCOMPILERDIR/lib/MaxIDE/plugins/org.hamcrest.core_1.1.0.v20090501071000.jar
export MAXCOMPILER=$MAXCOMPILERDIR/lib/MaxCompiler.jar
export MAXCOMPILERJCP=$MAXCOMPILERDIR/lib/ecj.jar:$MAXCOMPILERDIR/lib/MaxCompiler.jar:$MAXCOMPILERDIR/lib/Max5Platform.jar:$MAXPOWERDIR/lib/MaxPower.jar
export MAXAPPJCP=$APPDIR/bin
export MAXSOURCEDIRS=$APPDIR/src
export MAXMPPRMAILTO=$USER@ic.ac.uk

#update binaries (calls ant)
ant

#run
exec 5>&1
buildOutput=$(maxJavaRun MCSSManager "${@:1}" | tee >(cat - >&5))
result=$?


# Regex to select "MaxFile: /path/to/build/dir/MaxFileName" from the output of maxJavaRun
if [[ "${buildOutput}" =~ MaxFile:[[:space:]][^.]+ ]]; then
    includingMaxFile=${BASH_REMATCH}
	# Get rid of the front "MaxFile: " so we just have the file location without extension
	if [[ $includingMaxFile =~ /[^.]+  ]]; then
		#
		# copy max file to directory specific to build hash
		#
		echo "Copying files from ${BASH_REMATCH} to $(pwd)/../CPU/"
		cp ${BASH_REMATCH}.max ../CPU/max
		cp ${BASH_REMATCH}.h ../CPU/inc
		exit $result
	fi
fi
echo Could not find MaxFile
exit -1
