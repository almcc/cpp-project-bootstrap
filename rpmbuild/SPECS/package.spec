Name:           app
Version:        1.0.0
Release:        1%{?dist}
Summary:        C++ Command Line Tool

Group:          Development/Tools		
License:        MIT
URL:            https://github.com/almcc/cpp-makefile
Source0:        cpp.tar

%define  debug_package %{nil}

#BuildRequires:  
#Requires:       

%description


%prep

%setup -n cpp

%build
make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT
echo $(shell pwd)

%clean
rm -rf $RPM_BUILD_ROOT

%files
/usr/local/bin/main

%defattr(-,root,root,-)
%doc

%changelog
