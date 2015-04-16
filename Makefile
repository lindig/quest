# vim:ts=8 sw=4 noet:
#

PREFIX  = $(HOME)
BINDIR  = $(PREFIX)/bin
MAN1DIR = $(PREFIX)/man/man1
OCB	= ocamlbuild


LIPSUM  = https://github.com/lindig/lipsum.git
LP	= ./lipsum/lipsum.native

all:	src
	$(OCB) -I lua-ml -I src -libs unix src/main.native

src:	FORCE
	$(MAKE) -C lua-ml all
	$(MAKE) -C src all

clean:	FORCE
	$(OCB) -clean
	$(MAKE) -C lua-ml $@
	$(MAKE) -C src $@
	rm -f url descr

install: all
	install main.native $(BINDIR)/$(NAME)

remove:	FORCE
	rm -f $(BINDIR)/$(NAME)

remove:	FORCE


# OPAM - the targets below help to publish this code via opam.ocaml.org

NAME =		quest
VERSION =	0.1
TAG =		v$(VERSION)
GITHUB =	https://github.com/lindig/$(NAME)
ZIP =		$(GITHUB)/archive/$(TAG).zip
OPAM =		$(HOME)/Development/opam-repository/packages/$(NAME)/$(NAME).$(VERSION)

tag:
		git tag $(TAG)

descr:		README.md
		sed -n '/^# Opam/,$$ { /^#/n; p;}' $< >$@

url:		FORCE
		# echo	"archive: \"$(ZIP)\"" > url
		# echo	"checksum: \"`curl -L $(ZIP)| md5 -q`\"" >> url
		echo	'git: "https://github.com/lindig/$(NAME).git"' > url

release:	url opam descr sanity
		test -d "$(OPAM)" || mkdir -p $(OPAM)
		cp opam url descr $(OPAM)

sanity:		descr opam
		grep -q 'version: "$(VERSION)"' opam
		sed -n 1p descr | grep -q $(NAME)
		# grep -q 'version = "$(VERSION)"' META

# pseudo target

FORCE:;
