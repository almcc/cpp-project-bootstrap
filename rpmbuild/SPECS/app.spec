Name:           app
Version:        0.1.0
Release:        1%{?dist}
Summary:        C++ Command Line Tool

Group:          Development/Tools
License:        MIT
URL:            https://github.com/almcc/cpp-makefile
Source0:        %{name}-%{version}.tar.gz

%define  debug_package %{nil}

%description

%prep

%setup -n %{name}-%{version}

%build
make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT

%clean
rm -rf $RPM_BUILD_ROOT

%files
/usr/local/bin/app

%defattr(-,root,root,-)
%doc

%changelog
